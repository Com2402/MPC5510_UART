#include "MPC5510.h"

#define UART            eSCI_A      /* dùng eSCI_A */
#define BAUDRATE        115200U

#define PLL_PREDIV      3U          /* chia trước */
#define PLL_MFD         24U         /* nhân PLL */

/* Giả sử clock nguồn XOSC = 8 MHz
 * f_sys = 8MHz * (MFD+4)/(PREDIV+1)
 * f_sys = 8 * 28 / 4 = 56 MHz
 */
#define SYS_CLOCK_HZ    56000000UL

#define UART_SBR(clk, baud)   ((clk) / (16U * (baud)))

int main(void)
{
    uint32_t sbr;

    /* 1. Enable clock source (XOSC) */
    CRP->CRP_CLKSRC |= CRP_CLKSRC_XOSC_EN_MASK;

    /*  2. Configure FMPLL*/
    FMPLL->ESYNCR1 =
          FMPLL_ESYNCR1_PLLEN_MASK
        | (PLL_PREDIV << FMPLL_ESYNCR1_PREDIV_SHIFT)
        | (PLL_MFD    << FMPLL_ESYNCR1_MFD_SHIFT);

    /* Wait PLL lock */
    while (!(FMPLL->SYNSR & FMPLL_SYNSR_LOCK_MASK));

    /*  3. Disable TX/RX */
    UART->ESCIx_CR1 &= ~(ESCIx_CR1_TE_MASK | ESCIx_CR1_RE_MASK);

    /* 4. UART format: 8N1 */
    UART->ESCIx_CR1 &= ~ESCIx_CR1_M_MASK;   /* 8-bit */
    UART->ESCIx_CR1 &= ~ESCIx_CR1_PE_MASK;  /* no parity */
    UART->ESCIx_CR2 &= ~ESCIx_CR2_BRK13_MASK;

    /* 5. Baudrate */
    sbr = UART_SBR(SYS_CLOCK_HZ, BAUDRATE);
    UART->ESCIx_CR1 =
        (UART->ESCIx_CR1 & ~ESCIx_CR1_SBR_MASK)
        | ESCIx_CR1_SBR(sbr);

    /* 6. Enable TX & RX */
    UART->ESCIx_CR1 |= (ESCIx_CR1_TE_MASK | ESCIx_CR1_RE_MASK);

    while (1)
    {

        while (!(UART->ESCIx_SR & ESCIx_SR_RDRF_MASK));
        uint16_t ch = UART->ESCIx_DR & ESCIx_DR_RX_DATA_MASK;

        while (!(UART->ESCIx_SR & ESCIx_SR_TDRE_MASK));
        UART->ESCIx_DR = ESCIx_DR_TX_DATA(ch);
    }
}