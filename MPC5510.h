#if !defined (MPC_5510_H)
#define MPC_5510_H
#include <stdint.h>

#ifndef __IO
#ifdef __cplusplus
  #define   __I     volatile             /*!< Defines 'read only' permissions                 */
#else
  #define   __I     volatile const       /*!< Defines 'read only' permissions                 */
#endif
#define     __O     volatile             /*!< Defines 'write only' permissions                */
#define     __IO    volatile             /*!< Defines 'read / write' permissions              */
#endif


/**
* @brief 32 bits memory read macro.
*/
#if !defined(REG_READ32)
  #define REG_READ32(address)               (*(volatile uint32_t*)(address))
#endif

/**
* @brief 32 bits memory write macro.
*/
#if !defined(REG_WRITE32)
  #define REG_WRITE32(address, value)       ((*(volatile uint32_t*)(address))= (uint32_t)(value))
#endif

/**
* @brief 32 bits bits setting macro.
*/
#if !defined(REG_BIT_SET32)
  #define REG_BIT_SET32(address, mask)      ((*(volatile uint32_t*)(address))|= (uint32_t)(mask))
#endif

/**
* @brief 32 bits bits clearing macro.
*/
#if !defined(REG_BIT_CLEAR32)
  #define REG_BIT_CLEAR32(address, mask)    ((*(volatile uint32_t*)(address))&= ((uint32_t)~((uint32_t)(mask))))
#endif

/**
* @brief 32 bit clear bits and set with new value
* @note It is user's responsability to make sure that value has only "mask" bits set - (value&~mask)==0
*/
#if !defined(REG_RMW32)
  #define REG_RMW32(address, mask, value)   (REG_WRITE32((address), ((REG_READ32(address)& ((uint32_t)~((uint32_t)(mask))))| ((uint32_t)(value)))))
#endif

/* ----------------------------------------------------------------------------
   -- CRP Peripheral Access Layer
   ---------------------------------------------------------------------------- */
/** CRP - Register Layout Typedef */
typedef struct{
    __IO uint32_t CRP_CLKSRC;
    __IO uint32_t CRP_RTCSC;
    __I uint32_t CRP_RTCCNT;
    __IO uint32_t CRP_WKPINSEL;
    __IO uint32_t CRP_WKSE;
    __IO uint32_t CRP_Z1VEC;
    __IO uint32_t CRP_Z0VEC;
    __IO uint32_t CRP_RECPTR;
    __IO uint32_t CRP_PSCR;
    __IO uint32_t CRP_SOCSC;
}CRP_Type, *CRP_MemMapPtr;
/* ----------------------------------------------------------------------------
   -- eSCI Peripheral Access Layer
   ---------------------------------------------------------------------------- */
/** eSCI - Size of Registers Arrays */

/** eSCI - Register Layout Typedef */

typedef struct{
    __IO uint32_t ESCIx_CR1;          /** eSCI Control Register 1, offset: 0x0000 */
    __IO uint32_t ESCIx_CR2;          /** eSCI Control Register 2, offset: 0x0004 */
    __IO uint16_t ESCIx_DR;           /** eSCI Data Register, offset: 0x0006 */
    uint16_t RESERVED0;               /** Reserved, offset: 0x0006 (padding) */
    __I uint32_t ESCIx_SR;            /** eSCI Status Register, offset: 0x0008 */
    __IO uint32_t ESCIx_LCR;          /** LIN Control Register, offset: 0x000C */
    __IO uint32_t ESCIx_LTR;          /** LIN Transmit Register, offset: 0x0010 */
    __IO uint32_t ESCIx_LRR;          /** LIN Receive Register, offset: 0x0014 */
    __I uint32_t ESCIx_LPR;           /** LIN cyclic redundancy check (CRC) polynomial register, offset: 0x0018 */
}eSCI_Type, *eSCI_MemMapPtr;

/** Number of instances of the eSCI module. */
#define eSCI_INSTANCE_COUNT           (8u)

/* eSCI - Peripheral instance base addresses */
/** Peripheral eSCI_A base address */
#define eSCI_A_BASE                   (0xFFFA0000u)
/** Peripheral eSCI_A base pointer */
#define eSCI_A                        ((eSCI_Type*)eSCI_A_BASE)
/** Peripheral eSCI_B base address */
#define eSCI_B_BASE                   (0xFFFA4000u)
/** Peripheral eSCI_B base pointer */
#define eSCI_B                        ((eSCI_Type*)eSCI_B_BASE)
/** Peripheral eSCI_C base address */
#define eSCI_C_BASE                   (0xFFFA8000u)
/** Peripheral eSCI_C base pointer */
#define eSCI_C                        ((eSCI_Type*)eSCI_C_BASE)
/** Peripheral eSCI_D base address */
#define eSCI_D_BASE                   (0xFFFAC000u)
/** Peripheral eSCI_D base pointer */
#define eSCI_D                        ((eSCI_Type*)eSCI_D_BASE)
/** Peripheral eSCI_E base address */
#define eSCI_E_BASE                   (0xFFFB0000u)
/** Peripheral eSCI_E base pointer */
#define eSCI_E                        ((eSCI_Type*)eSCI_E_BASE)
/** Peripheral eSCI_F base address */
#define eSCI_F_BASE                   (0xFFFB4000u)
/** Peripheral eSCI_F base pointer */
#define eSCI_F                        ((eSCI_Type*)eSCI_F_BASE)
/** Peripheral eSCI_G base address */
#define eSCI_G_BASE                   (0xFFFB8000u)
/** Peripheral eSCI_G base pointer */
#define eSCI_G                        ((eSCI_Type*)eSCI_G_BASE)
/** Peripheral eSCI_H base address */
#define eSCI_H_BASE                   (0xFFFBC000u)
/** Peripheral eSCI_H base pointer */
#define eSCI_H                        ((eSCI_Type*)eSCI_H_BASE)

/* ----------------------------------------------------------------------------
   -- eSCI Register Masks
   ---------------------------------------------------------------------------- */
/* ESCIx_CR1 Bit Fields */
#define ESCIx_CR1_SBR_MASK            (0x1FFF0000u)
#define ESCIx_CR1_SBR_SHIFT           (16u)
#define ESCIx_CR1_SBR_WIDTH           (13u)
#define ESCIx_CR1_SBR(x)              (((uint32_t)(((uint32_t)(x))<<ESCIx_CR1_SBR_SHIFT))&ESCIx_CR1_SBR_MASK)
#define ESCIx_CR1_LOOPS_MASK          (0x0008000u)
#define ESCIx_CR1_LOOPS_SHIFT         (15u)
#define ESCIx_CR1_LOOPS_WIDTH         (1u)
#define ESCIx_CR1_LOOPS(x)            (((uint32_t)(((uint32_t)(x))<<ESCIx_CR1_LOOPS_SHIFT))&ESCIx_CR1_LOOPS_MASK)
#define ESCIx_CR1_RSRC_MASK           (0x00020000u)
#define ESCIx_CR1_RSRC_SHIFT          (13u)
#define ESCIx_CR1_RSRC_WIDTH          (1u)
#define ESCIx_CR1_RSRC(x)             (((uint32_t)(((uint32_t)(x))<<ESCIx_CR1_RSRC_SHIFT))&ESCIx_CR1_RSRC_MASK)
#define ESCIx_CR1_M_MASK              (0x00001000u)
#define ESCIx_CR1_M_SHIFT             (12u)
#define ESCIx_CR1_M_WIDTH             (1u)
#define ESCIx_CR1_M(x)                (((uint32_t)(((uint32_t)(x))<<ESCIx_CR1_M_SHIFT))&ESCIx_CR1_M_MASK)
#define ESCIx_CR1_WAKE_MASK           (0x00000800u)
#define ESCIx_CR1_WAKE_SHIFT          (11u)
#define ESCIx_CR1_WAKE_WIDTH          (1u)
#define ESCIx_CR1_WAKE(x)             (((uint32_t)(((uint32_t)(x))<<ESCIx_CR1_WAKE_SHIFT))&ESCIx_CR1_WAKE_MASK)
#define ESCIx_CR1_ILT_MASK            (0x00000400u)
#define ESCIx_CR1_ILT_SHIFT           (10u)
#define ESCIx_CR1_ILT_WIDTH           (1u)
#define ESCIx_CR1_ILT(x)              (((uint32_t)(((uint32_t)(x))<<ESCIx_CR1_ILT_SHIFT))&ESCIx_CR1_ILT_MASK)
#define ESCIx_CR1_PE_MASK             (0x00000200u)
#define ESCIx_CR1_PE_SHIFT            (9u)
#define ESCIx_CR1_PE_WIDTH            (1u)
#define ESCIx_CR1_PE(x)               (((uint32_t)(((uint32_t)(x))<<ESCIx_CR1_PE_SHIFT))&ESCIx_CR1_PE_MASK)
#define ESCIx_CR1_PT_MASK             (0x00000100u)
#define ESCIx_CR1_PT_SHIFT            (8u)
#define ESCIx_CR1_PT_WIDTH            (1u)
#define ESCIx_CR1_PT(x)               (((uint32_t)(((uint32_t)(x))<<ESCIx_CR1_PT_SHIFT))&ESCIx_CR1_PT_MASK)
#define ESCIx_CR1_TIE_MASK            (0x00000080u)
#define ESCIx_CR1_TIE_SHIFT           (7u)
#define ESCIx_CR1_TIE_WIDTH           (1u)
#define ESCIx_CR1_TIE(x)              (((uint32_t)(((uint32_t)(x))<<ESCIx_CR1_TIE_SHIFT))&ESCIx_CR1_TIE_MASK)
#define ESCIx_CR1_TCIE_MASK           (0x00000040u)
#define ESCIx_CR1_TCIE_SHIFT          (6u)
#define ESCIx_CR1_TCIE_WIDTH          (1u)
#define ESCIx_CR1_TCIE(x)             (((uint32_t)(((uint32_t)(x))<<ESCIx_CR1_TCIE_SHIFT))&ESCIx_CR1_TCIE_MASK)
#define ESCIx_CR1_RIE_MASK            (0x00000020u)
#define ESCIx_CR1_RIE_SHIFT           (5u)
#define ESCIx_CR1_RIE_WIDTH           (1u)
#define ESCIx_CR1_RIE(x)              (((uint32_t)(((uint32_t)(x))<<ESCIx_CR1_RIE_SHIFT))&ESCIx_CR1_RIE_MASK)
#define ESCIx_CR1_ILIE_MASK           (0x00000010u)
#define ESCIx_CR1_ILIE_SHIFT          (4u)
#define ESCIx_CR1_ILIE_WIDTH          (1u)
#define ESCIx_CR1_ILIE(x)             (((uint32_t)(((uint32_t)(x))<<ESCIx_CR1_ILIE_SHIFT))&ESCIx_CR1_ILIE_MASK)
#define ESCIx_CR1_TE_MASK             (0x00000008u)
#define ESCIx_CR1_TE_SHIFT            (3u)
#define ESCIx_CR1_TE_WIDTH            (1u)
#define ESCIx_CR1_TE(x)               (((uint32_t)(((uint32_t)(x))<<ESCIx_CR1_TE_SHIFT))&ESCIx_CR1_TE_MASK)
#define ESCIx_CR1_RE_MASK             (0x00000004u)
#define ESCIx_CR1_RE_SHIFT            (2u)
#define ESCIx_CR1_RE_WIDTH            (1u)
#define ESCIx_CR1_RE(x)               (((uint32_t)(((uint32_t)(x))<<ESCIx_CR1_RE_SHIFT))&ESCIx_CR1_RE_MASK)
#define ESCIx_CR1_RWU_MASK            (0x00000002u)
#define ESCIx_CR1_RWU_SHIFT           (1u)
#define ESCIx_CR1_RWU_WIDTH           (1u)
#define ESCIx_CR1_RWU(x)              (((uint32_t)(((uint32_t)(x))<<ESCIx_CR1_RWU_SHIFT))&ESCIx_CR1_RWU_MASK)
#define ESCIx_CR1_SBK_MASK            (0x00000001u)
#define ESCIx_CR1_SBK_SHIFT           (0u)
#define ESCIx_CR1_SBK_WIDTH           (1u)
#define ESCIx_CR1_SBK(x)              (((uint32_t)(((uint32_t)(x))<<ESCIx_CR1_SBK_SHIFT))&ESCIx_CR1_SBK_MASK)
/* ESCIx_CR2 Bit Fields */
#define ESCIx_CR2_MDIS_MASK           (0x80000000u)
#define ESCIx_CR2_MDIS_SHIFT          (31u)
#define ESCIx_CR2_MDIS_WIDTH          (1u)
#define ESCIx_CR2_MDIS(x)             (((uint32_t)(((uint32_t)(x))<<ESCIx_CR2_MDIS_SHIFT))&ESCIx_CR2_MDIS_MASK)
#define ESCIx_CR2_FBR_MASK            (0x40000000u)
#define ESCIx_CR2_FBR_SHIFT           (30u)
#define ESCIx_CR2_FBR_WIDTH           (1u)
#define ESCIx_CR2_FBR(x)              (((uint32_t)(((uint32_t)(x))<<ESCIx_CR2_FBR_SHIFT))&ESCIx_CR2_FBR_MASK)
#define ESCIx_CR2_BSTP_MASK           (0x20000000u)
#define ESCIx_CR2_BSTP_SHIFT          (29u)
#define ESCIx_CR2_BSTP_WIDTH          (1u)
#define ESCIx_CR2_BSTP(x)             (((uint32_t)(((uint32_t)(x))<<ESCIx_CR2_BSTP_SHIFT))&ESCIx_CR2_BSTP_MASK)
#define ESCIx_CR2_IEBERR_MASK         (0x10000000u)
#define ESCIx_CR2_IEBERR_SHIFT        (28u)
#define ESCIx_CR2_IEBERR_WIDTH        (1u)
#define ESCIx_CR2_IEBERR(x)           (((uint32_t)(((uint32_t)(x))<<ESCIx_CR2_IEBERR_SHIFT))&ESCIx_CR2_IEBERR_MASK)
#define ESCIx_CR2_RXDMA_MASK          (0x08000000u)
#define ESCIx_CR2_RXDMA_SHIFT         (27u)
#define ESCIx_CR2_RXDMA_WIDTH         (1u)
#define ESCIx_CR2_RXDMA(x)            (((uint32_t)(((uint32_t)(x))<<ESCIx_CR2_RXDMA_SHIFT))&ESCIx_CR2_RXDMA_MASK)
#define ESCIx_CR2_TXDMA_MASK          (0x04000000u)
#define ESCIx_CR2_TXDMA_SHIFT         (26u)
#define ESCIx_CR2_TXDMA_WIDTH         (1u)
#define ESCIx_CR2_TXDMA(x)            (((uint32_t)(((uint32_t)(x))<<ESCIx_CR2_TXDMA_SHIFT))&ESCIx_CR2_TXDMA_MASK)
#define ESCIx_CR2_BRK13_MASK          (0x02000000u)
#define ESCIx_CR2_BRK13_SHIFT         (25u)
#define ESCIx_CR2_BRK13_WIDTH         (1u)
#define ESCIx_CR2_BRK13(x)            (((uint32_t)(((uint32_t)(x))<<ESCIx_CR2_BRK13_SHIFT))&ESCIx_CR2_BRK13_MASK)
#define ESCIx_CR2_TXDIR_MASK          (0x01000000u)
#define ESCIx_CR2_TXDIR_SHIFT         (24u)
#define ESCIx_CR2_TXDIR_WIDTH         (1u)
#define ESCIx_CR2_TXDIR(x)            (((uint32_t)(((uint32_t)(x))<<ESCIx_CR2_TXDIR_SHIFT))&ESCIx_CR2_TXDIR_MASK)
#define ESCIx_CR2_BESM13_MASK         (0x00800000u)
#define ESCIx_CR2_BESM13_SHIFT        (23u)
#define ESCIx_CR2_BESM13_WIDTH        (1u)
#define ESCIx_CR2_BESM13(x)           (((uint32_t)(((uint32_t)(x))<<ESCIx_CR2_BESM13_SHIFT))&ESCIx_CR2_BESM13_MASK)
#define ESCIx_CR2_SBSTP_MASK          (0x00400000u)
#define ESCIx_CR2_SBSTP_SHIFT         (22u)
#define ESCIx_CR2_SBSTP_WIDTH         (1u)
#define ESCIx_CR2_SBSTP(x)            (((uint32_t)(((uint32_t)(x))<<ESCIx_CR2_SBSTP_SHIFT))&ESCIx_CR2_SBSTP_MASK)
#define ESCIx_CR2_PMSK_MASK           (0x00080000u)
#define ESCIx_CR2_PMSK_SHIFT          (19u)
#define ESCIx_CR2_PMSK_WIDTH          (1u)
#define ESCIx_CR2_PMSK(x)             (((uint32_t)(((uint32_t)(x))<<ESCIx_CR2_PMSK_SHIFT))&ESCIx_CR2_PMSK_MASK)
#define ESCIx_CR2_ORIE_MASK           (0x00040000u)
#define ESCIx_CR2_ORIE_SHIFT          (18u)
#define ESCIx_CR2_ORIE_WIDTH          (1u)
#define ESCIx_CR2_ORIE(x)             (((uint32_t)(((uint32_t)(x))<<ESCIx_CR2_ORIE_SHIFT))&ESCIx_CR2_ORIE_MASK)
#define ESCIx_CR2_NFIE_MASK           (0x00020000u)
#define ESCIx_CR2_NFIE_SHIFT          (17u)
#define ESCIx_CR2_NFIE_WIDTH          (1u)
#define ESCIx_CR2_NFIE(x)             (((uint32_t)(((uint32_t)(x))<<ESCIx_CR2_NFIE_SHIFT))&ESCIx_CR2_NFIE_MASK)
#define ESCIx_CR2_FEIE_MASK           (0x00010000u)
#define ESCIx_CR2_FEIE_SHIFT          (16u)
#define ESCIx_CR2_FEIE_WIDTH          (1u)
#define ESCIx_CR2_FEIE(x)             (((uint32_t)(((uint32_t)(x))<<ESCIx_CR2_FEIE_SHIFT))&ESCIx_CR2_FEIE_MASK)
#define ESCIx_CR2_PFIE_MASK           (0x00008000u)
#define ESCIx_CR2_PFIE_SHIFT          (15u)
#define ESCIx_CR2_PFIE_WIDTH          (1u)
#define ESCIx_CR2_PFIE(x)             (((uint32_t)(((uint32_t)(x))<<ESCIx_CR2_PFIE_SHIFT))&ESCIx_CR2_PFIE_MASK)
/* ESCIx_DR Bit Fields */
#define ESCIx_DR_R8_MASK              (0x8000u)
#define ESCIx_DR_R8_SHIFT             (15u)
#define ESCIx_DR_R8_WIDTH             (1u)
#define ESCIx_DR_R8(x)                (((uint16_t)(((uint16_t)(x))<<ESCIx_DR_R8_SHIFT))&ESCIx_DR_R8_MASK)
#define ESCIx_DR_T8_MASK              (0x4000u)
#define ESCIx_DR_T8_SHIFT             (14u)
#define ESCIx_DR_T8_WIDTH             (1u)
#define ESCIx_DR_T8(x)                (((uint16_t)(((uint16_t)(x))<<ESCIx_DR_T8_SHIFT))&ESCIx_DR_T8_MASK)
#define ESCIx_DR_R7_MASK              (0x0080u)
#define ESCIx_DR_R7_SHIFT             (7u)
#define ESCIx_DR_R7_WIDTH             (1u)
#define ESCIx_DR_R7(x)                (((uint16_t)(((uint16_t)(x))<<ESCIx_DR_R7_SHIFT))&ESCIx_DR_R7_MASK)
#define ESCIx_DR_T7_MASK              (0x0080u)
#define ESCIx_DR_T7_SHIFT             (7u)
#define ESCIx_DR_T7_WIDTH             (1u)
#define ESCIx_DR_T7(x)                (((uint16_t)(((uint16_t)(x))<<ESCIx_DR_T7_SHIFT))&ESCIx_DR_T7_MASK)
#define ESCIx_DR_R6_MASK              (0x0040u)
#define ESCIx_DR_R6_SHIFT             (6u)
#define ESCIx_DR_R6_WIDTH             (1u)
#define ESCIx_DR_R6(x)                (((uint16_t)(((uint16_t)(x))<<ESCIx_DR_R6_SHIFT))&ESCIx_DR_R6_MASK)
#define ESCIx_DR_T6_MASK              (0x0040u)
#define ESCIx_DR_T6_SHIFT             (6u)
#define ESCIx_DR_T6_WIDTH             (1u)
#define ESCIx_DR_T6(x)                (((uint16_t)(((uint16_t)(x))<<ESCIx_DR_T6_SHIFT))&ESCIx_DR_T6_MASK)
#define ESCIx_DR_R5_MASK              (0x0020u)
#define ESCIx_DR_R5_SHIFT             (5u)
#define ESCIx_DR_R5_WIDTH             (1u)
#define ESCIx_DR_R5(x)                (((uint16_t)(((uint16_t)(x))<<ESCIx_DR_R5_SHIFT))&ESCIx_DR_R5_MASK)
#define ESCIx_DR_T5_MASK              (0x0020u)
#define ESCIx_DR_T5_SHIFT             (5u)
#define ESCIx_DR_T5_WIDTH             (1u)
#define ESCIx_DR_T5(x)                (((uint16_t)(((uint16_t)(x))<<ESCIx_DR_T5_SHIFT))&ESCIx_DR_T5_MASK)
#define ESCIx_DR_R4_MASK              (0x0010u)
#define ESCIx_DR_R4_SHIFT             (4u)
#define ESCIx_DR_R4_WIDTH             (1u)
#define ESCIx_DR_R4(x)                (((uint16_t)(((uint16_t)(x))<<ESCIx_DR_R4_SHIFT))&ESCIx_DR_R4_MASK)
#define ESCIx_DR_T4_MASK              (0x0010u)
#define ESCIx_DR_T4_SHIFT             (4u)
#define ESCIx_DR_T4_WIDTH             (1u)
#define ESCIx_DR_T4(x)                (((uint16_t)(((uint16_t)(x))<<ESCIx_DR_T4_SHIFT))&ESCIx_DR_T4_MASK)
#define ESCIx_DR_R3_MASK              (0x0008u)
#define ESCIx_DR_R3_SHIFT             (3u)
#define ESCIx_DR_R3_WIDTH             (1u)
#define ESCIx_DR_R3(x)                (((uint16_t)(((uint16_t)(x))<<ESCIx_DR_R3_SHIFT))&ESCIx_DR_R3_MASK)
#define ESCIx_DR_T3_MASK              (0x0008u)
#define ESCIx_DR_T3_SHIFT             (3u)
#define ESCIx_DR_T3_WIDTH             (1u)
#define ESCIx_DR_T3(x)                (((uint16_t)(((uint16_t)(x))<<ESCIx_DR_T3_SHIFT))&ESCIx_DR_T3_MASK)
#define ESCIx_DR_R2_MASK              (0x0004u)
#define ESCIx_DR_R2_SHIFT             (2u)
#define ESCIx_DR_R2_WIDTH             (1u)
#define ESCIx_DR_R2(x)                (((uint16_t)(((uint16_t)(x))<<ESCIx_DR_R2_SHIFT))&ESCIx_DR_R2_MASK)
#define ESCIx_DR_T2_MASK              (0x0004u)
#define ESCIx_DR_T2_SHIFT             (2u)
#define ESCIx_DR_T2_WIDTH             (1u)
#define ESCIx_DR_T2(x)                (((uint16_t)(((uint16_t)(x))<<ESCIx_DR_T2_SHIFT))&ESCIx_DR_T2_MASK)
#define ESCIx_DR_R1_MASK              (0x0002u)
#define ESCIx_DR_R1_SHIFT             (1u)
#define ESCIx_DR_R1_WIDTH             (1u)
#define ESCIx_DR_R1(x)                (((uint16_t)(((uint16_t)(x))<<ESCIx_DR_R1_SHIFT))&ESCIx_DR_R1_MASK)
#define ESCIx_DR_T1_MASK              (0x0002u)
#define ESCIx_DR_T1_SHIFT             (1u)
#define ESCIx_DR_T1_WIDTH             (1u)
#define ESCIx_DR_T1(x)                (((uint16_t)(((uint16_t)(x))<<ESCIx_DR_T1_SHIFT))&ESCIx_DR_T1_MASK)
#define ESCIx_DR_R0_MASK              (0x0001u)
#define ESCIx_DR_R0_SHIFT             (0u)
#define ESCIx_DR_R0_WIDTH             (1u)
#define ESCIx_DR_R0(x)                (((uint16_t)(((uint16_t)(x))<<ESCIx_DR_R0_SHIFT))&ESCIx_DR_R0_MASK)
#define ESCIx_DR_T0_MASK              (0x0001u)
#define ESCIx_DR_T0_SHIFT             (0u)
#define ESCIx_DR_T0_WIDTH             (1u)
#define ESCIx_DR_T0(x)                (((uint16_t)(((uint16_t)(x))<<ESCIx_DR_T0_SHIFT))&ESCIx_DR_T0_MASK)
/* Convenient macros for full byte access */
/* RX_DATA - Received Data (bits 0-7 for 8-bit and bits 0-8 for 9-bit) */
#define ESCIx_DR_RX_DATA_MASK         (0x00FFu)  /* 8-bit data */
#define ESCIx_DR_RX_DATA_9BIT_MASK    (0x81FFu)  /* 9-bit data (R8 + R7-R0) */
#define ESCIx_DR_RX_DATA_SHIFT        (0u)
/* TX_DATA - Transmit Data (bits 0-7 for 8-bit and bits 0-8 for 9-bit) */
#define ESCIx_DR_TX_DATA_MASK         (0x00FFu)  /* 8-bit data */
#define ESCIx_DR_TX_DATA_9BIT_MASK    (0x41FFu)  /* 9-bit data (T8 + T7-T0) */
#define ESCIx_DR_TX_DATA_SHIFT        (0u)
#define ESCIx_DR_TX_DATA(x)           ((uint16_t)(x) & ESCIx_DR_TX_DATA_MASK)
/* ESCIx_SR Bit Fields */
#define ESCIx_SR_TDRE_MASK            (0x80000000u)
#define ESCIx_SR_TDRE_SHIFT           (31u)
#define ESCIx_SR_TDRE_WIDTH           (1u)
#define ESCIx_SR_TDRE(x)              (((uint32_t)(((uint32_t)(x))<<ESCIx_SR_TDRE_SHIFT))&ESCIx_SR_TDRE_MASK)
#define ESCIx_SR_TC_MASK              (0x40000000u)
#define ESCIx_SR_TC_SHIFT             (30u)
#define ESCIx_SR_TC_WIDTH             (1u)
#define ESCIx_SR_TC(x)                (((uint32_t)(((uint32_t)(x))<<ESCIx_SR_TC_SHIFT))&ESCIx_SR_TC_MASK)
#define ESCIx_SR_RDRF_MASK            (0x20000000u)
#define ESCIx_SR_RDRF_SHIFT           (29u)
#define ESCIx_SR_RDRF_WIDTH           (1u)
#define ESCIx_SR_RDRF(x)              (((uint32_t)(((uint32_t)(x))<<ESCIx_SR_RDRF_SHIFT))&ESCIx_SR_RDRF_MASK)
#define ESCIx_SR_IDLE_MASK            (0x10000000u)
#define ESCIx_SR_IDLE_SHIFT           (28u)
#define ESCIx_SR_IDLE_WIDTH           (1u)
#define ESCIx_SR_IDLE(x)              (((uint32_t)(((uint32_t)(x))<<ESCIx_SR_IDLE_SHIFT))&ESCIx_SR_IDLE_MASK)
#define ESCIx_SR_OR_MASK              (0x08000000u)
#define ESCIx_SR_OR_SHIFT             (27u)
#define ESCIx_SR_OR_WIDTH             (1u)
#define ESCIx_SR_OR(x)                (((uint32_t)(((uint32_t)(x))<<ESCIx_SR_OR_SHIFT))&ESCIx_SR_OR_MASK)
#define ESCIx_SR_NF_MASK              (0x04000000u)
#define ESCIx_SR_NF_SHIFT             (26u)
#define ESCIx_SR_NF_WIDTH             (1u)
#define ESCIx_SR_NF(x)                (((uint32_t)(((uint32_t)(x))<<ESCIx_SR_NF_SHIFT))&ESCIx_SR_NF_MASK)
#define ESCIx_SR_FE_MASK              (0x02000000u)
#define ESCIx_SR_FE_SHIFT             (25u)
#define ESCIx_SR_FE_WIDTH             (1u)
#define ESCIx_SR_FE(x)                (((uint32_t)(((uint32_t)(x))<<ESCIx_SR_FE_SHIFT))&ESCIx_SR_FE_MASK)
#define ESCIx_SR_PF_MASK              (0x01000000u)
#define ESCIx_SR_PF_SHIFT             (24u)
#define ESCIx_SR_PF_WIDTH             (1u)
#define ESCIx_SR_PF(x)                (((uint32_t)(((uint32_t)(x))<<ESCIx_SR_PF_SHIFT))&ESCIx_SR_PF_MASK)
#define ESCIx_SR_BERR_MASK            (0x00100000u)
#define ESCIx_SR_BERR_SHIFT           (20u)
#define ESCIx_SR_BERR_WIDTH           (1u)
#define ESCIx_SR_BERR(x)              (((uint32_t)(((uint32_t)(x))<<ESCIx_SR_BERR_SHIFT))&ESCIx_SR_BERR_MASK)
#define ESCIx_SR_RAF_MASK             (0x00010000u)
#define ESCIx_SR_RAF_SHIFT            (16u)
#define ESCIx_SR_RAF_WIDTH            (1u)
#define ESCIx_SR_RAF(x)               (((uint32_t)(((uint32_t)(x))<<ESCIx_SR_RAF_SHIFT))&ESCIx_SR_RAF_MASK)
#define ESCIx_SR_RXRDY_MASK           (0x00008000u)
#define ESCIx_SR_RXRDY_SHIFT          (15u)
#define ESCIx_SR_RXRDY_WIDTH          (1u)
#define ESCIx_SR_RXRDY(x)             (((uint32_t)(((uint32_t)(x))<<ESCIx_SR_RXRDY_SHIFT))&ESCIx_SR_RXRDY_MASK)
#define ESCIx_SR_TXRDY_MASK           (0x00004000u)
#define ESCIx_SR_TXRDY_SHIFT          (14u)
#define ESCIx_SR_TXRDY_WIDTH          (1u)
#define ESCIx_SR_TXRDY(x)             (((uint32_t)(((uint32_t)(x))<<ESCIx_SR_TXRDY_SHIFT))&ESCIx_SR_TXRDY_MASK)
#define ESCIx_SR_LWAKE_MASK           (0x00002000u)
#define ESCIx_SR_LWAKE_SHIFT          (13u)
#define ESCIx_SR_LWAKE_WIDTH          (1u)
#define ESCIx_SR_LWAKE(x)             (((uint32_t)(((uint32_t)(x))<<ESCIx_SR_LWAKE_SHIFT))&ESCIx_SR_LWAKE_MASK)
#define ESCIx_SR_STO_MASK             (0x00001000u)
#define ESCIx_SR_STO_SHIFT            (12u)
#define ESCIx_SR_STO_WIDTH            (1u)
#define ESCIx_SR_STO(x)               (((uint32_t)(((uint32_t)(x))<<ESCIx_SR_STO_SHIFT))&ESCIx_SR_STO_MASK)
#define ESCIx_SR_PBERR_MASK           (0x00000800u)
#define ESCIx_SR_PBERR_SHIFT          (11u)
#define ESCIx_SR_PBERR_WIDTH          (1u)
#define ESCIx_SR_PBERR(x)             (((uint32_t)(((uint32_t)(x))<<ESCIx_SR_PBERR_SHIFT))&ESCIx_SR_PBERR_MASK)
#define ESCIx_SR_CERR_MASK            (0x00000400u)
#define ESCIx_SR_CERR_SHIFT           (10u)
#define ESCIx_SR_CERR_WIDTH           (1u)
#define ESCIx_SR_CERR(x)              (((uint32_t)(((uint32_t)(x))<<ESCIx_SR_CERR_SHIFT))&ESCIx_SR_CERR_MASK)
#define ESCIx_SR_CKERR_MASK           (0x00000200u)
#define ESCIx_SR_CKERR_SHIFT          (9u)
#define ESCIx_SR_CKERR_WIDTH          (1u)
#define ESCIx_SR_CKERR(x)             (((uint32_t)(((uint32_t)(x))<<ESCIx_SR_CKERR_SHIFT))&ESCIx_SR_CKERR_MASK)
#define ESCIx_SR_FRC_MASK             (0x00000100u)
#define ESCIx_SR_FRC_SHIFT            (8u)
#define ESCIx_SR_FRC_WIDTH            (1u)
#define ESCIx_SR_FRC(x)               (((uint32_t)(((uint32_t)(x))<<ESCIx_SR_FRC_SHIFT))&ESCIx_SR_FRC_MASK)
#define ESCIx_SR_UREQ_MASK            (0x00000002u)
#define ESCIx_SR_UREQ_SHIFT           (1u)
#define ESCIx_SR_UREQ_WIDTH           (1u)
#define ESCIx_SR_UREQ(x)              (((uint32_t)(((uint32_t)(x))<<ESCIx_SR_UREQ_SHIFT))&ESCIx_SR_UREQ_MASK)
#define ESCIx_SR_OVFL_MASK            (0x00000001u)
#define ESCIx_SR_OVFL_SHIFT           (0u)
#define ESCIx_SR_OVFL_WIDTH           (1u)
#define ESCIx_SR_OVFL(x)              (((uint32_t)(((uint32_t)(x))<<ESCIx_SR_OVFL_SHIFT))&ESCIx_SR_OVFL_MASK)
/* Convenient macros for error flags */
#define ESCIx_SR_ERROR_FLAGS_MASK                (0x0F100000u)  /* OR|NF|FE|PF|BERR */
#define ESCIx_SR_LIN_ERROR_FLAGS_MASK            (0x00001E00u)  /* STO|PBERR|CERR|CKERR */
/* ESCIx_LCR Bit Fields */
#define ESCIx_LCR_LRES_MASK           (0x80000000u)
#define ESCIx_LCR_LRES_SHIFT          (31u)
#define ESCIx_LCR_LRES_WIDTH          (1u)
#define ESCIx_LCR_LRES(x)             (((uint32_t)(((uint32_t)(x))<<ESCIx_LCR_LRES_SHIFT))&ESCIx_LCR_LRES_MASK)
#define ESCIx_LCR_WU_MASK             (0x40000000u)
#define ESCIx_LCR_WU_SHIFT            (30u)
#define ESCIx_LCR_WU_WIDTH            (1u)
#define ESCIx_LCR_WU(x)               (((uint32_t)(((uint32_t)(x))<<ESCIx_LCR_WU_SHIFT))&ESCIx_LCR_WU_MASK)
#define ESCIx_LCR_WUD0_MASK           (0x20000000u)
#define ESCIx_LCR_WUD0_SHIFT          (29u)
#define ESCIx_LCR_WUD0_WIDTH          (1u)
#define ESCIx_LCR_WUD0(x)             (((uint32_t)(((uint32_t)(x))<<ESCIx_LCR_WUD0_SHIFT))&ESCIx_LCR_WUD0_MASK)
#define ESCIx_LCR_WUD1_MASK           (0x10000000u)
#define ESCIx_LCR_WUD1_SHIFT          (28u)
#define ESCIx_LCR_WUD1_WIDTH          (1u)
#define ESCIx_LCR_WUD1(x)             (((uint32_t)(((uint32_t)(x))<<ESCIx_LCR_WUD1_SHIFT))&ESCIx_LCR_WUD1_MASK)
#define ESCIx_LCR_LDBG_MASK           (0x08000000u)
#define ESCIx_LCR_LDBG_SHIFT          (27u)
#define ESCIx_LCR_LDBG_WIDTH          (1u)
#define ESCIx_LCR_LDBG(x)             (((uint32_t)(((uint32_t)(x))<<ESCIx_LCR_LDBG_SHIFT))&ESCIx_LCR_LDBG_MASK)
#define ESCIx_LCR_DSF_MASK            (0x04000000u)
#define ESCIx_LCR_DSF_SHIFT           (26u)
#define ESCIx_LCR_DSF_WIDTH           (1u)
#define ESCIx_LCR_DSF(x)              (((uint32_t)(((uint32_t)(x))<<ESCIx_LCR_DSF_SHIFT))&ESCIx_LCR_DSF_MASK)
#define ESCIx_LCR_PRTY_MASK           (0x02000000u)
#define ESCIx_LCR_PRTY_SHIFT          (25u)
#define ESCIx_LCR_PRTY_WIDTH          (1u)
#define ESCIx_LCR_PRTY(x)             (((uint32_t)(((uint32_t)(x))<<ESCIx_LCR_PRTY_SHIFT))&ESCIx_LCR_PRTY_MASK)
#define ESCIx_LCR_LIN_MASK            (0x01000000u)
#define ESCIx_LCR_LIN_SHIFT           (24u)
#define ESCIx_LCR_LIN_WIDTH           (1u)
#define ESCIx_LCR_LIN(x)              (((uint32_t)(((uint32_t)(x))<<ESCIx_LCR_LIN_SHIFT))&ESCIx_LCR_LIN_MASK)
#define ESCIx_LCR_RXIE_MASK           (0x00800000u)
#define ESCIx_LCR_RXIE_SHIFT          (23u)
#define ESCIx_LCR_RXIE_WIDTH          (1u)
#define ESCIx_LCR_RXIE(x)             (((uint32_t)(((uint32_t)(x))<<ESCIx_LCR_RXIE_SHIFT))&ESCIx_LCR_RXIE_MASK)
#define ESCIx_LCR_TXIE_MASK           (0x00400000u)
#define ESCIx_LCR_TXIE_SHIFT          (22u)
#define ESCIx_LCR_TXIE_WIDTH          (1u)
#define ESCIx_LCR_TXIE(x)             (((uint32_t)(((uint32_t)(x))<<ESCIx_LCR_TXIE_SHIFT))&ESCIx_LCR_TXIE_MASK)
#define ESCIx_LCR_WUIE_MASK           (0x00200000u)
#define ESCIx_LCR_WUIE_SHIFT          (21u)
#define ESCIx_LCR_WUIE_WIDTH          (1u)
#define ESCIx_LCR_WUIE(x)             (((uint32_t)(((uint32_t)(x))<<ESCIx_LCR_WUIE_SHIFT))&ESCIx_LCR_WUIE_MASK)
#define ESCIx_LCR_STIE_MASK           (0x00100000u)
#define ESCIx_LCR_STIE_SHIFT          (20u)
#define ESCIx_LCR_STIE_WIDTH          (1u)
#define ESCIx_LCR_STIE(x)             (((uint32_t)(((uint32_t)(x))<<ESCIx_LCR_STIE_SHIFT))&ESCIx_LCR_STIE_MASK)
#define ESCIx_LCR_PBIE_MASK           (0x00080000u)
#define ESCIx_LCR_PBIE_SHIFT          (19u)
#define ESCIx_LCR_PBIE_WIDTH          (1u)
#define ESCIx_LCR_PBIE(x)             (((uint32_t)(((uint32_t)(x))<<ESCIx_LCR_PBIE_SHIFT))&ESCIx_LCR_PBIE_MASK)
#define ESCIx_LCR_CIE_MASK            (0x00040000u)
#define ESCIx_LCR_CIE_SHIFT           (18u)
#define ESCIx_LCR_CIE_WIDTH           (1u)
#define ESCIx_LCR_CIE(x)              (((uint32_t)(((uint32_t)(x))<<ESCIx_LCR_CIE_SHIFT))&ESCIx_LCR_CIE_MASK)
#define ESCIx_LCR_CKIE_MASK           (0x00020000u)
#define ESCIx_LCR_CKIE_SHIFT          (17u)
#define ESCIx_LCR_CKIE_WIDTH          (1u)
#define ESCIx_LCR_CKIE(x)             (((uint32_t)(((uint32_t)(x))<<ESCIx_LCR_CKIE_SHIFT))&ESCIx_LCR_CKIE_MASK)
#define ESCIx_LCR_FCIE_MASK           (0x00010000u)
#define ESCIx_LCR_FCIE_SHIFT          (16u)
#define ESCIx_LCR_FCIE_WIDTH          (1u)
#define ESCIx_LCR_FCIE(x)             (((uint32_t)(((uint32_t)(x))<<ESCIx_LCR_FCIE_SHIFT))&ESCIx_LCR_FCIE_MASK)
#define ESCIx_LCR_UQIE_MASK           (0x00000200u)
#define ESCIx_LCR_UQIE_SHIFT          (9u)
#define ESCIx_LCR_UQIE_WIDTH          (1u)
#define ESCIx_LCR_UQIE(x)             (((uint32_t)(((uint32_t)(x))<<ESCIx_LCR_UQIE_SHIFT))&ESCIx_LCR_UQIE_MASK)
#define ESCIx_LCR_OFIE_MASK           (0x00000100u)
#define ESCIx_LCR_OFIE_SHIFT          (8u)
#define ESCIx_LCR_OFIE_WIDTH          (1u)
#define ESCIx_LCR_OFIE(x)             (((uint32_t)(((uint32_t)(x))<<ESCIx_LCR_OFIE_SHIFT))&ESCIx_LCR_OFIE_MASK)
/* ESCIx_LTR Bit Fields */
#define ESCIx_LTR_P_MASK              (0xC0000000u)
#define ESCIx_LTR_P_SHIFT             (30u)
#define ESCIx_LTR_P_WIDTH             (2u)
#define ESCIx_LTR_P(x)                (((uint32_t)(((uint32_t)(x))<<ESCIx_LTR_P_SHIFT))&ESCIx_LTR_P_MASK)
#define ESCIx_LTR_ID_MASK             (0x3F000000u)
#define ESCIx_LTR_ID_SHIFT            (24u)
#define ESCIx_LTR_ID_WIDTH            (6u)
#define ESCIx_LTR_ID(x)               (((uint32_t)(((uint32_t)(x))<<ESCIx_LTR_ID_SHIFT))&ESCIx_LTR_ID_MASK)
#define ESCIx_LTR_L_MASK              (0xFF000000u)
#define ESCIx_LTR_L_SHIFT             (24u)
#define ESCIx_LTR_L_WIDTH             (8u)
#define ESCIx_LTR_L(x)                (((uint32_t)(((uint32_t)(x))<<ESCIx_LTR_L_SHIFT))&ESCIx_LTR_L_MASK)
#define ESCIx_LTR_HDCHK_MASK          (0x80000000u)
#define ESCIx_LTR_HDCHK_SHIFT         (31u)
#define ESCIx_LTR_HDCHK_WIDTH         (1u)
#define ESCIx_LTR_HDCHK(x)            (((uint32_t)(((uint32_t)(x))<<ESCIx_LTR_HDCHK_SHIFT))&ESCIx_LTR_HDCHK_MASK)
#define ESCIx_LTR_CSUM_MASK           (0x40000000u)
#define ESCIx_LTR_CSUM_SHIFT          (30u)
#define ESCIx_LTR_CSUM_WIDTH          (1u)
#define ESCIx_LTR_CSUM(x)             (((uint32_t)(((uint32_t)(x))<<ESCIx_LTR_CSUM_SHIFT))&ESCIx_LTR_CSUM_MASK)
#define ESCIx_LTR_CRC_MASK            (0x20000000u)
#define ESCIx_LTR_CRC_SHIFT           (29u)
#define ESCIx_LTR_CRC_WIDTH           (1u)
#define ESCIx_LTR_CRC(x)              (((uint32_t)(((uint32_t)(x))<<ESCIx_LTR_CRC_SHIFT))&ESCIx_LTR_CRC_MASK)
#define ESCIx_LTR_TX_MASK             (0x10000000u)
#define ESCIx_LTR_TX_SHIFT            (28u)
#define ESCIx_LTR_TX_WIDTH            (1u)
#define ESCIx_LTR_TX(x)               (((uint32_t)(((uint32_t)(x))<<ESCIx_LTR_TX_SHIFT))&ESCIx_LTR_TX_MASK)
/* RX - Alias for TX (RX mode when TX=0) */
#define ESCIx_LTR_RX_MASK             ESCIx_LTR_TX_MASK
#define ESCIx_LTR_RX_SHIFT            ESCIx_LTR_TX_SHIFT
#define ESCIx_LTR_RX(x)               ESCIx_LTR_TX(x)
#define ESCIx_LTR_T_11_8_MASK         (0x0F000000u)
#define ESCIx_LTR_T_11_8_SHIFT        (24u)
#define ESCIx_LTR_T_11_8_WIDTH        (4u)
#define ESCIx_LTR_T_11_8(x)           (((uint32_t)(((uint32_t)(x))<<ESCIx_LTR_T_11_8_SHIFT))&ESCIx_LTR_T_11_8_MASK)
#define ESCIx_LTR_T_7_0_MASK          (0xFF000000u)
#define ESCIx_LTR_T_7_0_SHIFT         (24u)
#define ESCIx_LTR_T_7_0_WIDTH         (8u)
#define ESCIx_LTR_T_7_0(x)            (((uint32_t)(((uint32_t)(x))<<ESCIx_LTR_T_7_0_SHIFT))&ESCIx_LTR_T_7_0_MASK)
#define ESCIx_LTR_D_MASK              (0xFF000000u)
#define ESCIx_LTR_D_SHIFT             (24u)
#define ESCIx_LTR_D_WIDTH             (8u)
#define ESCIx_LTR_D(x)                (((uint32_t)(((uint32_t)(x))<<ESCIx_LTR_D_SHIFT))&ESCIx_LTR_D_MASK)
/* ESCIx_LRR Bit Field */
#define ESCIx_LRR_D_MASK              (0xFF000000u)
#define ESCIx_LRR_D_SHIFT             (24u)
#define ESCIx_LRR_D_WIDTH             (8u)
#define ESCIx_LRR_D(x)                (((uint32_t)(((uint32_t)(x))<<ESCIx_LRR_D_SHIFT))&ESCIx_LRR_D_MASK)
/* ESCIx_LPR Bit Field*/
#define ESCIx_LPR_P_MASK              (0xFFFF0000u)
#define ESCIx_LPR_P_SHIFT             (16u)
#define ESCIx_LPR_P_WIDTH             (16u)
#define ESCIx_LPR_P(x)                (((uint32_t)(((uint32_t)(x))<<ESCIx_LPR_P_SHIFT))&ESCIx_LPR_P_MASK)
#endif /*MPC_5510_H*/