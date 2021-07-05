/* Generated automatically by the program 'build/genpreds'
   from the machine description file '../../gcc/config/sh/sh.md'.  */

#ifndef GCC_TM_PREDS_H
#define GCC_TM_PREDS_H

#ifdef HAVE_MACHINE_MODES
extern int general_operand (rtx, enum machine_mode);
extern int address_operand (rtx, enum machine_mode);
extern int register_operand (rtx, enum machine_mode);
extern int pmode_register_operand (rtx, enum machine_mode);
extern int scratch_operand (rtx, enum machine_mode);
extern int immediate_operand (rtx, enum machine_mode);
extern int const_int_operand (rtx, enum machine_mode);
extern int const_double_operand (rtx, enum machine_mode);
extern int nonimmediate_operand (rtx, enum machine_mode);
extern int nonmemory_operand (rtx, enum machine_mode);
extern int push_operand (rtx, enum machine_mode);
extern int pop_operand (rtx, enum machine_mode);
extern int memory_operand (rtx, enum machine_mode);
extern int indirect_operand (rtx, enum machine_mode);
extern int ordered_comparison_operator (rtx, enum machine_mode);
extern int comparison_operator (rtx, enum machine_mode);
extern int trapping_target_operand (rtx, enum machine_mode);
extern int and_operand (rtx, enum machine_mode);
extern int any_arith_reg_dest (rtx, enum machine_mode);
extern int any_register_operand (rtx, enum machine_mode);
extern int arith_operand (rtx, enum machine_mode);
extern int arith_reg_dest (rtx, enum machine_mode);
extern int arith_reg_operand (rtx, enum machine_mode);
extern int arith_reg_or_0_operand (rtx, enum machine_mode);
extern int binary_float_operator (rtx, enum machine_mode);
extern int binary_logical_operator (rtx, enum machine_mode);
extern int cache_address_operand (rtx, enum machine_mode);
extern int cmp_operand (rtx, enum machine_mode);
extern int cmpsi_operand (rtx, enum machine_mode);
extern int commutative_float_operator (rtx, enum machine_mode);
extern int equality_comparison_operator (rtx, enum machine_mode);
extern int extend_reg_operand (rtx, enum machine_mode);
extern int extend_reg_or_0_operand (rtx, enum machine_mode);
extern int ext_dest_operand (rtx, enum machine_mode);
extern int fp_arith_reg_dest (rtx, enum machine_mode);
extern int fp_arith_reg_operand (rtx, enum machine_mode);
extern int fpscr_operand (rtx, enum machine_mode);
extern int fpul_operand (rtx, enum machine_mode);
extern int general_extend_operand (rtx, enum machine_mode);
extern int general_movsrc_operand (rtx, enum machine_mode);
extern int general_movdst_operand (rtx, enum machine_mode);
extern int sh_no_delay_pop_operand (rtx, enum machine_mode);
extern int unaligned_load_operand (rtx, enum machine_mode);
extern int greater_comparison_operator (rtx, enum machine_mode);
extern int inqhi_operand (rtx, enum machine_mode);
extern int int_gpr_dest (rtx, enum machine_mode);
extern int less_comparison_operator (rtx, enum machine_mode);
extern int logical_operand (rtx, enum machine_mode);
extern int logical_operator (rtx, enum machine_mode);
extern int logical_reg_operand (rtx, enum machine_mode);
extern int mextr_bit_offset (rtx, enum machine_mode);
extern int minuend_operand (rtx, enum machine_mode);
extern int noncommutative_float_operator (rtx, enum machine_mode);
extern int sh_float_comparison_operator (rtx, enum machine_mode);
extern int shmedia_cbranch_comparison_operator (rtx, enum machine_mode);
extern int sh_const_vec (rtx, enum machine_mode);
extern int sh_1el_vec (rtx, enum machine_mode);
extern int sh_register_operand (rtx, enum machine_mode);
extern int sh_rep_vec (rtx, enum machine_mode);
extern int shift_count_operand (rtx, enum machine_mode);
extern int shift_count_reg_operand (rtx, enum machine_mode);
extern int shift_operator (rtx, enum machine_mode);
extern int symbol_ref_operand (rtx, enum machine_mode);
extern int soft_fp_comparison_operand (rtx, enum machine_mode);
extern int soft_fp_comparison_operator (rtx, enum machine_mode);
extern int target_operand (rtx, enum machine_mode);
extern int target_reg_operand (rtx, enum machine_mode);
extern int trunc_hi_operand (rtx, enum machine_mode);
extern int ua_address_operand (rtx, enum machine_mode);
extern int ua_offset (rtx, enum machine_mode);
extern int unary_float_operator (rtx, enum machine_mode);
extern int xor_operand (rtx, enum machine_mode);
extern int bitwise_memory_operand (rtx, enum machine_mode);
#endif /* HAVE_MACHINE_MODES */

#define CONSTRAINT_NUM_DEFINED_P 1
enum constraint_num
{
  CONSTRAINT__UNKNOWN = 0,
  CONSTRAINT_a,
  CONSTRAINT_b,
  CONSTRAINT_c,
  CONSTRAINT_d,
  CONSTRAINT_e,
  CONSTRAINT_f,
  CONSTRAINT_k,
  CONSTRAINT_l,
  CONSTRAINT_t,
  CONSTRAINT_u,
  CONSTRAINT_w,
  CONSTRAINT_x,
  CONSTRAINT_y,
  CONSTRAINT_z,
  CONSTRAINT_R03,
  CONSTRAINT_I06,
  CONSTRAINT_I08,
  CONSTRAINT_I10,
  CONSTRAINT_I16,
  CONSTRAINT_I20,
  CONSTRAINT_I28,
  CONSTRAINT_J16,
  CONSTRAINT_K03,
  CONSTRAINT_K08,
  CONSTRAINT_K12,
  CONSTRAINT_K16,
  CONSTRAINT_P27,
  CONSTRAINT_M,
  CONSTRAINT_N,
  CONSTRAINT_G,
  CONSTRAINT_H,
  CONSTRAINT_Q,
  CONSTRAINT_Bsc,
  CONSTRAINT_Css,
  CONSTRAINT_Csu,
  CONSTRAINT_Csy,
  CONSTRAINT_Z,
  CONSTRAINT_W,
  CONSTRAINT_Cpg,
  CONSTRAINT_Pso,
  CONSTRAINT_Psz,
  CONSTRAINT_Sr0,
  CONSTRAINT_Sua,
  CONSTRAINT_Sbv,
  CONSTRAINT_Sbw,
  CONSTRAINT__LIMIT
};

extern enum constraint_num lookup_constraint (const char *);
extern bool constraint_satisfied_p (rtx, enum constraint_num);

static inline size_t
insn_constraint_len (char fc, const char *str ATTRIBUTE_UNUSED)
{
  switch (fc)
    {
    case 'B': return 3;
    case 'C': return 3;
    case 'I': return 3;
    case 'J': return 3;
    case 'K': return 3;
    case 'P': return 3;
    case 'R': return 3;
    case 'S': return 3;
    default: break;
    }
  return 1;
}

#define CONSTRAINT_LEN(c_,s_) insn_constraint_len (c_,s_)

extern enum reg_class regclass_for_constraint (enum constraint_num);
#define REG_CLASS_FROM_CONSTRAINT(c_,s_) \
    regclass_for_constraint (lookup_constraint (s_))
#define REG_CLASS_FOR_CONSTRAINT(x_) \
    regclass_for_constraint (x_)

extern bool insn_const_int_ok_for_constraint (HOST_WIDE_INT, enum constraint_num);
#define CONST_OK_FOR_CONSTRAINT_P(v_,c_,s_) \
    insn_const_int_ok_for_constraint (v_, lookup_constraint (s_))

#define CONST_DOUBLE_OK_FOR_CONSTRAINT_P(v_,c_,s_) \
    constraint_satisfied_p (v_, lookup_constraint (s_))

#define EXTRA_CONSTRAINT_STR(v_,c_,s_) \
    constraint_satisfied_p (v_, lookup_constraint (s_))

extern bool insn_extra_memory_constraint (enum constraint_num);
#define EXTRA_MEMORY_CONSTRAINT(c_,s_) insn_extra_memory_constraint (lookup_constraint (s_))

#define EXTRA_ADDRESS_CONSTRAINT(c_,s_) false

#endif /* tm-preds.h */
