/* Generated automatically by the program `genflags'
   from the machine description file `md'.  */

#ifndef GCC_INSN_FLAGS_H
#define GCC_INSN_FLAGS_H

#define HAVE_tstsi2 (TARGET_SH1)
#define HAVE_cmpeqsi_t (TARGET_SH1)
#define HAVE_fpcmp_i1 (TARGET_SH1_SOFTFP)
#define HAVE_cmpgtsi_t (TARGET_SH1)
#define HAVE_cmpgesi_t (TARGET_SH1)
#define HAVE_cmpgeusi_t (TARGET_SH1)
#define HAVE_cmpgtusi_t (TARGET_SH1)
#define HAVE_cmpeqdi_t (TARGET_SH1)
#define HAVE_cmpgtdi_t (TARGET_SH2)
#define HAVE_cmpgedi_t (TARGET_SH2)
#define HAVE_cmpgeudi_t (TARGET_SH2)
#define HAVE_cmpgtudi_t (TARGET_SH2)
#define HAVE_cmpeqsi_media (TARGET_SHMEDIA)
#define HAVE_cmpeqdi_media (TARGET_SHMEDIA)
#define HAVE_cmpgtsi_media (TARGET_SHMEDIA)
#define HAVE_cmpgtdi_media (TARGET_SHMEDIA)
#define HAVE_cmpgtusi_media (TARGET_SHMEDIA)
#define HAVE_cmpgtudi_media (TARGET_SHMEDIA)
#define HAVE_movdicc_false (TARGET_SHMEDIA)
#define HAVE_movdicc_true (TARGET_SHMEDIA)
#define HAVE_movsicc_false (TARGET_SHMEDIA)
#define HAVE_movsicc_true (TARGET_SHMEDIA)
#define HAVE_adddi3z_media (TARGET_SHMEDIA)
#define HAVE_adddi3_compact (TARGET_SH1)
#define HAVE_addc (TARGET_SH1)
#define HAVE_addc1 (TARGET_SH1)
#define HAVE_addsi3_media (TARGET_SHMEDIA)
#define HAVE_addsidi3_media (TARGET_SHMEDIA)
#define HAVE_subdisi3_media (TARGET_SHMEDIA)
#define HAVE_subdi3_compact (TARGET_SH1)
#define HAVE_subc (TARGET_SH1)
#define HAVE_subc1 (TARGET_SH1)
#define HAVE_mov_neg_si_t (TARGET_SH1)
#define HAVE_use_sfunc_addr (TARGET_SH1 && check_use_sfunc_addr (insn, operands[0]))
#define HAVE_udivsi3_sh2a (TARGET_SH2A)
#define HAVE_udivsi3_i1 (TARGET_SH1 && ! TARGET_SH4)
#define HAVE_udivsi3_i1_media (TARGET_SHMEDIA && (! TARGET_SHMEDIA_FPU || ! TARGET_DIVIDE_FP))
#define HAVE_udivsi3_i4 (TARGET_SH4 && ! TARGET_FPU_SINGLE)
#define HAVE_udivsi3_i4_single ((TARGET_HARD_SH4 || TARGET_SHCOMPACT) && TARGET_FPU_SINGLE)
#define HAVE_udivsi3_i4_int (TARGET_SH1)
#define HAVE_divsi3_sh2a (TARGET_SH2A)
#define HAVE_divsi3_i1 (TARGET_SH1 && ! TARGET_SH4)
#define HAVE_divsi3_i1_media (TARGET_SHMEDIA && (! TARGET_SHMEDIA_FPU || ! TARGET_DIVIDE_FP))
#define HAVE_divsi3_media_2 (TARGET_SHMEDIA && (! TARGET_SHMEDIA_FPU || ! TARGET_DIVIDE_FP))
#define HAVE_divsi_inv_call (TARGET_SHMEDIA)
#define HAVE_divsi3_i4 (TARGET_SH4 && ! TARGET_FPU_SINGLE)
#define HAVE_divsi3_i4_single ((TARGET_HARD_SH4 || TARGET_SHCOMPACT) && TARGET_FPU_SINGLE)
#define HAVE_divsi3_i4_int (TARGET_SH1)
#define HAVE_divsi_inv_qitable (TARGET_SHMEDIA)
#define HAVE_divsi_inv_hitable (TARGET_SHMEDIA)
#define HAVE_divsi_inv_m1 (TARGET_SHMEDIA)
#define HAVE_divsi_inv_m2 (TARGET_SHMEDIA)
#define HAVE_divsi_inv_m3 (TARGET_SHMEDIA)
#define HAVE_divsi_inv_m1_3 (TARGET_SHMEDIA \
   && (TARGET_DIVIDE_INV_MINLAT \
       || TARGET_DIVIDE_INV20U || TARGET_DIVIDE_INV20L))
#define HAVE_divsi_inv20 (TARGET_SHMEDIA \
   && (TARGET_DIVIDE_INV20U || TARGET_DIVIDE_INV20L))
#define HAVE_divsi_inv_fp (TARGET_SHMEDIA_FPU)
#define HAVE_umulhisi3_i (TARGET_SH1)
#define HAVE_mulhisi3_i (TARGET_SH1)
#define HAVE_mul_r (TARGET_SH2A)
#define HAVE_mul_l (TARGET_SH2)
#define HAVE_mulr03 (TARGET_R0R3_TO_REG_MUL - !reload_completed >= 1)
#define HAVE_mulsidi3_i (TARGET_SH2)
#define HAVE_mulsidi3_media (TARGET_SHMEDIA)
#define HAVE_mulsidi3_compact (TARGET_SH2)
#define HAVE_umulsidi3_i (TARGET_SH2)
#define HAVE_umulsidi3_media (TARGET_SHMEDIA)
#define HAVE_umulsidi3_compact (TARGET_SH2)
#define HAVE_smulsi3_highpart_i (TARGET_SH2)
#define HAVE_umulsi3_highpart_i (TARGET_SH2)
#define HAVE_muldi3 (TARGET_SHMEDIA)
#define HAVE_anddi3 (TARGET_SHMEDIA)
#define HAVE_andcsi3 (TARGET_SHMEDIA)
#define HAVE_andcdi3 (TARGET_SHMEDIA)
#define HAVE_iordi3 (TARGET_SHMEDIA)
#define HAVE_xorsi3_movrt (TARGET_SH2A)
#define HAVE_xordi3 (TARGET_SHMEDIA)
#define HAVE_rotldi3_mextr (TARGET_SHMEDIA)
#define HAVE_rotrdi3_mextr (TARGET_SHMEDIA)
#define HAVE_rotlsi3_1 (TARGET_SH1)
#define HAVE_rotlsi3_31 (TARGET_SH1)
#define HAVE_rotlsi3_16 (TARGET_SH1)
#define HAVE_rotlhi3_8 (TARGET_SH1)
#define HAVE_ashlsi3_sh2a (TARGET_SH2A)
#define HAVE_ashlsi3_k (TARGET_SH1)
#define HAVE_ashlsi3_std (TARGET_SH3 \
   || (TARGET_SH1 && satisfies_constraint_P27 (operands[2])))
#define HAVE_ashlhi3_k (TARGET_SH1 && satisfies_constraint_P27 (operands[2]))
#define HAVE_ashlsi3_n (TARGET_SH1 && ! sh_dynamicalize_shift_p (operands[2]))
#define HAVE_ashlsi3_media (TARGET_SHMEDIA)
#define HAVE_ashrsi3_sh2a (TARGET_SH2A)
#define HAVE_ashrsi3_k (TARGET_SH1 && INTVAL (operands[2]) == 1)
#define HAVE_ashlsi_c (TARGET_SH1)
#define HAVE_ashrsi3_d (TARGET_SH3)
#define HAVE_ashrsi3_n (TARGET_SH1)
#define HAVE_ashrsi3_media (TARGET_SHMEDIA)
#define HAVE_lshrsi3_sh2a (TARGET_SH2A)
#define HAVE_lshrsi3_d (TARGET_SH3)
#define HAVE_lshrsi3_m (TARGET_SH1 && satisfies_constraint_M (operands[2]))
#define HAVE_lshrsi3_k (TARGET_SH1 && satisfies_constraint_P27 (operands[2]) \
   && ! satisfies_constraint_M (operands[2]))
#define HAVE_lshrsi3_n (TARGET_SH1 && ! sh_dynamicalize_shift_p (operands[2]))
#define HAVE_lshrsi3_media (TARGET_SHMEDIA)
#define HAVE_ashldi3_k (TARGET_SH1)
#define HAVE_ashldi3_media (TARGET_SHMEDIA)
#define HAVE_lshrdi3_k (TARGET_SH1)
#define HAVE_lshrdi3_media (TARGET_SHMEDIA \
   && (arith_reg_dest (operands[0], DImode) \
       || (CONST_INT_P (operands[2]) && INTVAL (operands[2]) > 32)))
#define HAVE_ashrdi3_k (TARGET_SH1)
#define HAVE_ashrdi3_media (TARGET_SHMEDIA \
   && (arith_reg_dest (operands[0], DImode) \
       || (CONST_INT_P (operands[2]) && INTVAL (operands[2]) >= 32)))
#define HAVE_ashrdisi3_media_high (TARGET_SHMEDIA && INTVAL (operands[2]) >= 32)
#define HAVE_ashrdisi3_media_opaque (TARGET_SHMEDIA)
#define HAVE_and_shl_scratch (TARGET_SH1)
#define HAVE_shl_sext_ext (TARGET_SH1 && (unsigned)shl_sext_kind (operands[2], operands[3], 0) - 1 < 5)
#define HAVE_shl_sext_sub (TARGET_SH1 && (shl_sext_kind (operands[2], operands[3], 0) & ~1) == 6)
#define HAVE_xtrct_left (TARGET_SH1)
#define HAVE_xtrct_right (TARGET_SH1)
#define HAVE_negc (TARGET_SH1)
#define HAVE_negsi2 (TARGET_SH1)
#define HAVE_one_cmplsi2 (TARGET_SH1)
#define HAVE_cneg (TARGET_HARD_SH4)
#define HAVE_zero_extendsidi2 (TARGET_SHMEDIA)
#define HAVE_zero_extendhidi2 (TARGET_SHMEDIA)
#define HAVE_zero_extendqidi2 (TARGET_SHMEDIA)
#define HAVE_zero_extendqihi2 (TARGET_SH1)
#define HAVE_extendsidi2 (TARGET_SHMEDIA)
#define HAVE_extendhidi2 (TARGET_SHMEDIA)
#define HAVE_extendqidi2 (TARGET_SHMEDIA)
#define HAVE_extendqihi2 (TARGET_SH1)
#define HAVE_truncdisi2 (TARGET_SHMEDIA)
#define HAVE_truncdihi2 (TARGET_SHMEDIA)
#define HAVE_truncdiqi2 (TARGET_SHMEDIA)
#define HAVE_push_fpul (TARGET_SH2E && ! TARGET_SH5)
#define HAVE_pop_fpul (TARGET_SH1 && ! TARGET_SH5)
#define HAVE_pop_fpul2 1
#define HAVE_clrt (TARGET_SH1)
#define HAVE_sett (TARGET_SH1)
#define HAVE_movsi_i (TARGET_SH1 \
   && ! TARGET_SH2E \
   && ! TARGET_SH2A \
   && (register_operand (operands[0], SImode) \
       || register_operand (operands[1], SImode)))
#define HAVE_movsi_ie ((TARGET_SH2E || TARGET_SH2A) \
   && (register_operand (operands[0], SImode) \
       || register_operand (operands[1], SImode)))
#define HAVE_movsi_i_lowpart (TARGET_SH1 \
    && (register_operand (operands[0], SImode) \
        || register_operand (operands[1], SImode)))
#define HAVE_load_ra (TARGET_SH1)
#define HAVE_ic_invalidate_line_i (TARGET_HARD_SH4)
#define HAVE_ic_invalidate_line_sh4a (TARGET_SH4A_ARCH || TARGET_SH4_300)
#define HAVE_ic_invalidate_line_media (TARGET_SHMEDIA)
#define HAVE_ic_invalidate_line_compact (TARGET_SHCOMPACT)
#define HAVE_initialize_trampoline_compact (TARGET_SHCOMPACT)
#define HAVE_movqi_i (TARGET_SH1 \
   && (arith_reg_operand (operands[0], QImode) \
       || arith_reg_operand (operands[1], QImode)))
#define HAVE_movhi_i (TARGET_SH1 \
   && (arith_reg_operand (operands[0], HImode) \
       || arith_reg_operand (operands[1], HImode)) \
   && (!MEM_P (operands[0]) \
       || GET_CODE (XEXP (operands[0], 0)) != PLUS \
       || !REG_P (XEXP (XEXP (operands[0], 0), 1)) \
       || ! refers_to_regno_p (R0_REG, R0_REG + 1, operands[1], (rtx *)0)))
#define HAVE_shori_media (TARGET_SHMEDIA && (reload_completed || arith_reg_dest (operands[0], DImode)))
#define HAVE_movdf_media (TARGET_SHMEDIA_FPU \
   && (register_operand (operands[0], DFmode) \
       || sh_register_operand (operands[1], DFmode)))
#define HAVE_movdf_media_nofpu (TARGET_SHMEDIA \
   && (register_operand (operands[0], DFmode) \
       || sh_register_operand (operands[1], DFmode)))
#define HAVE_movdf_k (TARGET_SH1 \
   && (! (TARGET_SH4 || TARGET_SH2A_DOUBLE) || reload_completed \
       /* ??? We provide some insn so that direct_{load,store}[DFmode] get set */ \
       || (REG_P (operands[0]) && REGNO (operands[0]) == 3) \
       || (REG_P (operands[1]) && REGNO (operands[1]) == 3)) \
   && (arith_reg_operand (operands[0], DFmode) \
       || arith_reg_operand (operands[1], DFmode)))
#define HAVE_movdf_i4 ((TARGET_SH4 || TARGET_SH2A_DOUBLE) \
   && (arith_reg_operand (operands[0], DFmode) \
       || arith_reg_operand (operands[1], DFmode)))
#define HAVE_movv2sf_i (TARGET_SHMEDIA_FPU)
#define HAVE_movsf_media (TARGET_SHMEDIA_FPU \
   && (register_operand (operands[0], SFmode) \
       || sh_register_operand (operands[1], SFmode)))
#define HAVE_movsf_media_nofpu (TARGET_SHMEDIA \
   && (register_operand (operands[0], SFmode) \
       || sh_register_operand (operands[1], SFmode)))
#define HAVE_movsf_i (TARGET_SH1 \
   && (! TARGET_SH2E \
       /* ??? We provide some insn so that direct_{load,store}[SFmode] get set */ \
       || (REG_P (operands[0]) && REGNO (operands[0]) == 3) \
       || (REG_P (operands[1]) && REGNO (operands[1]) == 3)) \
   && (arith_reg_operand (operands[0], SFmode) \
       || arith_reg_operand (operands[1], SFmode)))
#define HAVE_movsf_ie (TARGET_SH2E \
   && (arith_reg_operand (operands[0], SFmode) \
       || arith_reg_operand (operands[1], SFmode) \
       || arith_reg_operand (operands[3], SImode) \
       || (fpul_operand (operands[0], SFmode) \
	   && memory_operand (operands[1], SFmode) \
	   && GET_CODE (XEXP (operands[1], 0)) == POST_INC) \
       || (fpul_operand (operands[1], SFmode) \
	   && memory_operand (operands[0], SFmode) \
	   && GET_CODE (XEXP (operands[0], 0)) == PRE_DEC)))
#define HAVE_mov_nop (TARGET_SH2E)
#define HAVE_branch_true (TARGET_SH1)
#define HAVE_branch_false (TARGET_SH1)
#define HAVE_block_branch_redirect (TARGET_SH1)
#define HAVE_indirect_jump_scratch (TARGET_SH1)
#define HAVE_stuff_delay_slot (TARGET_SH1)
#define HAVE_doloop_end_split (TARGET_SH2)
#define HAVE_jump_compact (TARGET_SH1 && !find_reg_note (insn, REG_CROSSING_JUMP, NULL_RTX))
#define HAVE_jump_media (TARGET_SHMEDIA)
#define HAVE_force_mode_for_call (TARGET_SHCOMPACT)
#define HAVE_calli (TARGET_SH1)
#define HAVE_calli_tbr_rel (TARGET_SH2A && sh2a_is_function_vector_call (operands[0]))
#define HAVE_calli_pcrel (TARGET_SH2)
#define HAVE_call_pcrel (TARGET_SH2)
#define HAVE_call_compact (TARGET_SHCOMPACT && ! (INTVAL (operands[2]) & CALL_COOKIE_RET_TRAMP (1)))
#define HAVE_call_compact_rettramp (TARGET_SHCOMPACT && (INTVAL (operands[2]) & CALL_COOKIE_RET_TRAMP (1)))
#define HAVE_call_media (TARGET_SHMEDIA)
#define HAVE_call_valuei (TARGET_SH1)
#define HAVE_call_valuei_tbr_rel (TARGET_SH2A && sh2a_is_function_vector_call (operands[1]))
#define HAVE_call_valuei_pcrel (TARGET_SH2)
#define HAVE_call_value_pcrel (TARGET_SH2)
#define HAVE_call_value_compact (TARGET_SHCOMPACT && ! (INTVAL (operands[3]) & CALL_COOKIE_RET_TRAMP (1)))
#define HAVE_call_value_compact_rettramp (TARGET_SHCOMPACT && (INTVAL (operands[3]) & CALL_COOKIE_RET_TRAMP (1)))
#define HAVE_call_value_media (TARGET_SHMEDIA)
#define HAVE_call_pop_compact (TARGET_SHCOMPACT && ! (INTVAL (operands[2]) & CALL_COOKIE_RET_TRAMP (1)))
#define HAVE_call_pop_compact_rettramp (TARGET_SHCOMPACT && (INTVAL (operands[2]) & CALL_COOKIE_RET_TRAMP (1)))
#define HAVE_sibcalli (TARGET_SH1)
#define HAVE_sibcalli_pcrel (TARGET_SH2)
#define HAVE_sibcalli_thunk (TARGET_SH1)
#define HAVE_sibcall_pcrel (TARGET_SH2)
#define HAVE_sibcall_compact (TARGET_SHCOMPACT)
#define HAVE_sibcall_media (TARGET_SHMEDIA)
#define HAVE_sibcall_valuei (TARGET_SH1)
#define HAVE_sibcall_valuei_pcrel (TARGET_SH2)
#define HAVE_sibcall_value_pcrel (TARGET_SH2)
#define HAVE_sibcall_value_compact (TARGET_SHCOMPACT)
#define HAVE_sibcall_value_media (TARGET_SHMEDIA)
#define HAVE_call_value_pop_compact (TARGET_SHCOMPACT && ! (INTVAL (operands[3]) & CALL_COOKIE_RET_TRAMP (1)))
#define HAVE_call_value_pop_compact_rettramp (TARGET_SHCOMPACT && (INTVAL (operands[3]) & CALL_COOKIE_RET_TRAMP (1)))
#define HAVE_indirect_jump_compact (TARGET_SH1)
#define HAVE_casesi_jump_1 (TARGET_SH1)
#define HAVE_casesi_jump_2 (TARGET_SH2 \
   && (! INSN_UID (operands[1]) || prev_real_insn (operands[1]) == insn))
#define HAVE_casesi_jump_media (TARGET_SHMEDIA)
#define HAVE_dup_db_insn (TARGET_DEAD_DELAY)
#define HAVE_dect (TARGET_SH2)
#define HAVE_nop 1
#define HAVE_mova (TARGET_SH1)
#define HAVE_mova_const (TARGET_SH1)
#define HAVE_ptrel_si (TARGET_SHMEDIA)
#define HAVE_ptrel_di (TARGET_SHMEDIA)
#define HAVE_chk_guard_add (TARGET_SH1)
#define HAVE_tls_global_dynamic (TARGET_SH1)
#define HAVE_tls_local_dynamic (TARGET_SH1)
#define HAVE_tls_initial_exec 1
#define HAVE_load_gbr 1
#define HAVE_casesi_worker_0 (TARGET_SH1)
#define HAVE_casesi_worker_1 (TARGET_SH1)
#define HAVE_casesi_worker_2 (TARGET_SH2 && reload_completed && flag_pic)
#define HAVE_casesi_shift_media (TARGET_SHMEDIA)
#define HAVE_casesi_load_media (TARGET_SHMEDIA)
#define HAVE_shcompact_return_tramp_i (TARGET_SHCOMPACT \
   && (crtl->args.info.call_cookie & CALL_COOKIE_RET_TRAMP (1)))
#define HAVE_return_media_i (TARGET_SHMEDIA && reload_completed)
#define HAVE_return_media_rte (TARGET_SHMEDIA && reload_completed && current_function_interrupt)
#define HAVE_shcompact_preserve_incoming_args (TARGET_SHCOMPACT)
#define HAVE_shcompact_incoming_args (TARGET_SHCOMPACT)
#define HAVE_shmedia_save_restore_regs_compact (TARGET_SHCOMPACT \
   && (INTVAL (operands[0]) == SHMEDIA_REGS_STACK_ADJUST () \
       || INTVAL (operands[0]) == - SHMEDIA_REGS_STACK_ADJUST ()))
#define HAVE_eh_set_ra_si (! TARGET_SHMEDIA64)
#define HAVE_eh_set_ra_di (TARGET_SHMEDIA64)
#define HAVE_blockage 1
#define HAVE_movml_push_banked (TARGET_SH2A && REGNO (operands[0]) == 15)
#define HAVE_movml_pop_banked (TARGET_SH2A && REGNO (operands[0]) == 15)
#define HAVE_movt (TARGET_SH1)
#define HAVE_consttable_2 1
#define HAVE_consttable_4 1
#define HAVE_consttable_8 1
#define HAVE_consttable_sf 1
#define HAVE_consttable_df 1
#define HAVE_align_log 1
#define HAVE_consttable_end 1
#define HAVE_consttable_window_end 1
#define HAVE_block_move_real (TARGET_SH1 && ! TARGET_HARD_SH4)
#define HAVE_block_lump_real (TARGET_SH1 && ! TARGET_HARD_SH4)
#define HAVE_block_move_real_i4 (TARGET_HARD_SH4)
#define HAVE_block_lump_real_i4 (TARGET_HARD_SH4)
#define HAVE_cmpstr_t (TARGET_SH1)
#define HAVE_rotcr_t (TARGET_SH1)
#define HAVE_fpu_switch (TARGET_SH2E \
   && (! reload_completed \
       || true_regnum (operands[0]) != FPSCR_REG \
       || !MEM_P (operands[1]) \
       || GET_CODE (XEXP (operands[1], 0)) != PLUS))
#define HAVE_toggle_sz ((TARGET_SH4 || TARGET_SH2A_DOUBLE))
#define HAVE_toggle_pr ((TARGET_SH4A_FP || TARGET_SH4_300))
#define HAVE_unary_sf_op (TARGET_SHMEDIA_FPU)
#define HAVE_binary_sf_op0 (TARGET_SHMEDIA_FPU)
#define HAVE_binary_sf_op1 (TARGET_SHMEDIA_FPU)
#define HAVE_addsf3_i (TARGET_SH2E)
#define HAVE_subsf3_i (TARGET_SH2E)
#define HAVE_mulsf3_ie (TARGET_SH2E)
#define HAVE_mulsf3_i4 (TARGET_SH2E)
#define HAVE_mac_media (TARGET_SHMEDIA_FPU && TARGET_FMAC)
#define HAVE_divsf3_i (TARGET_SH2E)
#define HAVE_floatdisf2 (TARGET_SHMEDIA_FPU)
#define HAVE_floatsisf2_i4 ((TARGET_SH4 || TARGET_SH2A_SINGLE))
#define HAVE_fix_truncsfdi2 (TARGET_SHMEDIA_FPU)
#define HAVE_fix_truncsfsi2_i4 ((TARGET_SH4 || TARGET_SH2A_SINGLE))
#define HAVE_cmpgtsf_t (TARGET_SH2E && ! (TARGET_SH4 || TARGET_SH2A_SINGLE))
#define HAVE_cmpnesf_i1 (TARGET_SH1 && ! TARGET_SH2E)
#define HAVE_cmpgtsf_i1 (TARGET_SH1 && ! TARGET_SH2E)
#define HAVE_cmpunltsf_i1 (TARGET_SH1 && ! TARGET_SH2E)
#define HAVE_cmpeqsf_i1_finite (TARGET_SH1 && ! TARGET_SH2E && flag_finite_math_only)
#define HAVE_cmplesf_i1_finite (TARGET_SH1 && ! TARGET_SH2E && flag_finite_math_only)
#define HAVE_cmpunsf_i1 (TARGET_SH1 && ! TARGET_SH2E)
#define HAVE_cmpuneqsf_i1 (TARGET_SH1 && ! TARGET_SH2E)
#define HAVE_movcc_fp_ne (TARGET_SH1)
#define HAVE_movcc_fp_gt (TARGET_SH1)
#define HAVE_movcc_fp_unlt (TARGET_SH1)
#define HAVE_cmpeqsf_t (TARGET_SH2E && ! (TARGET_SH4 || TARGET_SH2A_SINGLE))
#define HAVE_ieee_ccmpeqsf_t (TARGET_SH2E && TARGET_IEEE && ! (TARGET_SH4 || TARGET_SH2A_SINGLE))
#define HAVE_cmpgtsf_t_i4 ((TARGET_SH4 || TARGET_SH2A_SINGLE))
#define HAVE_cmpeqsf_t_i4 ((TARGET_SH4 || TARGET_SH2A_SINGLE))
#define HAVE_cmpeqsf_media (TARGET_SHMEDIA_FPU)
#define HAVE_cmpgtsf_media (TARGET_SHMEDIA_FPU)
#define HAVE_cmpgesf_media (TARGET_SHMEDIA_FPU)
#define HAVE_cmpunsf_media (TARGET_SHMEDIA_FPU)
#define HAVE_negsf2_i (TARGET_SH2E)
#define HAVE_sqrtsf2_i (TARGET_SH3E)
#define HAVE_rsqrtsf2 (TARGET_SH4A_FP && flag_unsafe_math_optimizations \
   && operands[1] == CONST1_RTX (SFmode))
#define HAVE_fsca (TARGET_SH4A_FP && flag_unsafe_math_optimizations \
   && operands[2] == sh_fsca_int2sf ())
#define HAVE_abssf2_i (TARGET_SH2E)
#define HAVE_adddf3_i ((TARGET_SH4 || TARGET_SH2A_DOUBLE))
#define HAVE_adddf3_i3 (TARGET_SH3)
#define HAVE_subdf3_i ((TARGET_SH4 || TARGET_SH2A_DOUBLE))
#define HAVE_muldf3_i ((TARGET_SH4 || TARGET_SH2A_DOUBLE))
#define HAVE_muldf3_i3 (TARGET_SH3)
#define HAVE_divdf3_i ((TARGET_SH4 || TARGET_SH2A_DOUBLE))
#define HAVE_floatdidf2 (TARGET_SHMEDIA_FPU)
#define HAVE_floatsidf2_i ((TARGET_SH4 || TARGET_SH2A_DOUBLE))
#define HAVE_fix_truncdfdi2 (TARGET_SHMEDIA_FPU)
#define HAVE_fix_truncdfsi2_i ((TARGET_SH4 || TARGET_SH2A_DOUBLE))
#define HAVE_cmpnedf_i1 (TARGET_SH1_SOFTFP)
#define HAVE_cmpgtdf_i1 (TARGET_SH1_SOFTFP)
#define HAVE_cmpunltdf_i1 (TARGET_SH1_SOFTFP)
#define HAVE_cmpeqdf_i1_finite (TARGET_SH1_SOFTFP && flag_finite_math_only)
#define HAVE_cmpundf_i1 (TARGET_SH1 && ! TARGET_SH2E)
#define HAVE_cmpuneqdf_i1 (TARGET_SH1_SOFTFP)
#define HAVE_cmpgtdf_t ((TARGET_SH4 || TARGET_SH2A_DOUBLE))
#define HAVE_cmpeqdf_t ((TARGET_SH4 || TARGET_SH2A_DOUBLE))
#define HAVE_cmpeqdf_media (TARGET_SHMEDIA_FPU)
#define HAVE_cmpgtdf_media (TARGET_SHMEDIA_FPU)
#define HAVE_cmpgedf_media (TARGET_SHMEDIA_FPU)
#define HAVE_cmpundf_media (TARGET_SHMEDIA_FPU)
#define HAVE_negdf2_i ((TARGET_SH4 || TARGET_SH2A_DOUBLE))
#define HAVE_sqrtdf2_i ((TARGET_SH4 || TARGET_SH2A_DOUBLE))
#define HAVE_absdf2_i ((TARGET_SH4 || TARGET_SH2A_DOUBLE))
#define HAVE_extendsfdf2_i4 ((TARGET_SH4 || TARGET_SH2A_DOUBLE))
#define HAVE_extendsfdf2_i1 (TARGET_SH1_SOFTFP && !TARGET_SH2E)
#define HAVE_extendsfdf2_i1_r0 (TARGET_SH1_SOFTFP && !TARGET_SH2E)
#define HAVE_extendsfdf2_i2e (TARGET_SH1_SOFTFP && TARGET_SH2E)
#define HAVE_extendsfdf2_i2e_r0 (TARGET_SH1_SOFTFP && TARGET_SH2E)
#define HAVE_truncdfsf2_i4 ((TARGET_SH4 || TARGET_SH2A_DOUBLE))
#define HAVE_truncdfsf2_i1 (TARGET_SH1_SOFTFP && !TARGET_SH2E)
#define HAVE_truncdfsf2_i2e (TARGET_SH1_SOFTFP && TARGET_SH2E)
#define HAVE_movua (TARGET_SH4A_ARCH)
#define HAVE_bclr_m2a (TARGET_SH2A && TARGET_BITOPS)
#define HAVE_bclrmem_m2a (TARGET_SH2A && satisfies_constraint_Psz (operands[1]) && TARGET_BITOPS)
#define HAVE_bset_m2a (TARGET_SH2A && TARGET_BITOPS)
#define HAVE_bsetmem_m2a (TARGET_SH2A && satisfies_constraint_Pso (operands[1]) && TARGET_BITOPS)
#define HAVE_bst_m2a (TARGET_SH2A && TARGET_BITOPS)
#define HAVE_bld_m2a (TARGET_SH2A && TARGET_BITOPS)
#define HAVE_bldsign_m2a (TARGET_SH2A && TARGET_BITOPS)
#define HAVE_bld_reg (TARGET_SH2A)
#define HAVE_band_m2a (TARGET_SH2A && TARGET_BITOPS)
#define HAVE_bandreg_m2a (TARGET_SH2A && TARGET_BITOPS)
#define HAVE_bor_m2a (TARGET_SH2A && TARGET_BITOPS)
#define HAVE_borreg_m2a (TARGET_SH2A && TARGET_BITOPS)
#define HAVE_bxor_m2a (TARGET_SH2A && TARGET_BITOPS)
#define HAVE_bxorreg_m2a (TARGET_SH2A && TARGET_BITOPS)
#define HAVE_sp_switch_1 (TARGET_SH1)
#define HAVE_sp_switch_2 (TARGET_SH1)
#define HAVE_movv8qi_i (TARGET_SHMEDIA \
   && (register_operand (operands[0], V8QImode) \
       || sh_register_operand (operands[1], V8QImode)))
#define HAVE_movv2hi_i (TARGET_SHMEDIA \
   && (register_operand (operands[0], V2HImode) \
       || sh_register_operand (operands[1], V2HImode)))
#define HAVE_movv4hi_i (TARGET_SHMEDIA \
   && (register_operand (operands[0], V4HImode) \
       || sh_register_operand (operands[1], V4HImode)))
#define HAVE_movv2si_i (TARGET_SHMEDIA \
   && (register_operand (operands[0], V2SImode) \
       || sh_register_operand (operands[1], V2SImode)))
#define HAVE_absv2si2 (TARGET_SHMEDIA)
#define HAVE_absv4hi2 (TARGET_SHMEDIA)
#define HAVE_addv2si3 (TARGET_SHMEDIA)
#define HAVE_addv4hi3 (TARGET_SHMEDIA)
#define HAVE_addv2hi3 (TARGET_SHMEDIA)
#define HAVE_ssaddv2si3 (TARGET_SHMEDIA)
#define HAVE_usaddv8qi3 (TARGET_SHMEDIA)
#define HAVE_ssaddv4hi3 (TARGET_SHMEDIA)
#define HAVE_negcmpeqv8qi (TARGET_SHMEDIA)
#define HAVE_negcmpeqv2si (TARGET_SHMEDIA)
#define HAVE_negcmpeqv4hi (TARGET_SHMEDIA)
#define HAVE_negcmpgtuv8qi (TARGET_SHMEDIA)
#define HAVE_negcmpgtv2si (TARGET_SHMEDIA)
#define HAVE_negcmpgtv4hi (TARGET_SHMEDIA)
#define HAVE_mcmv (TARGET_SHMEDIA)
#define HAVE_mcnvs_lw (TARGET_SHMEDIA)
#define HAVE_mcnvs_wb (TARGET_SHMEDIA)
#define HAVE_mcnvs_wub (TARGET_SHMEDIA)
#define HAVE_mextr_rl (TARGET_SHMEDIA && INTVAL (operands[3]) + INTVAL (operands[4]) == 64)
#define HAVE_mmacfx_wl_i (TARGET_SHMEDIA)
#define HAVE_mmacnfx_wl_i (TARGET_SHMEDIA)
#define HAVE_mulv2si3 (TARGET_SHMEDIA)
#define HAVE_mulv4hi3 (TARGET_SHMEDIA)
#define HAVE_mmulfx_l (TARGET_SHMEDIA)
#define HAVE_mmulfx_w (TARGET_SHMEDIA)
#define HAVE_mmulfxrp_w (TARGET_SHMEDIA)
#define HAVE_mmul23_wl (TARGET_SHMEDIA)
#define HAVE_mmul01_wl (TARGET_SHMEDIA)
#define HAVE_mmulsum_wq_i (TARGET_SHMEDIA)
#define HAVE_mperm_w_little (TARGET_SHMEDIA && TARGET_LITTLE_ENDIAN)
#define HAVE_mperm_w_big (TARGET_SHMEDIA && ! TARGET_LITTLE_ENDIAN)
#define HAVE_mperm_w0 (TARGET_SHMEDIA)
#define HAVE_msad_ubq_i (TARGET_SHMEDIA)
#define HAVE_mshalds_l (TARGET_SHMEDIA)
#define HAVE_mshalds_w (TARGET_SHMEDIA)
#define HAVE_ashrv2si3 (TARGET_SHMEDIA)
#define HAVE_ashrv4hi3 (TARGET_SHMEDIA)
#define HAVE_mshards_q (TARGET_SHMEDIA)
#define HAVE_mshf4_b (TARGET_SHMEDIA)
#define HAVE_mshf0_b (TARGET_SHMEDIA)
#define HAVE_mshf4_l (TARGET_SHMEDIA)
#define HAVE_mshf0_l (TARGET_SHMEDIA)
#define HAVE_mshf4_w (TARGET_SHMEDIA)
#define HAVE_mshf0_w (TARGET_SHMEDIA)
#define HAVE_mshflo_w_x (TARGET_SHMEDIA)
#define HAVE_mshfhi_l_di (TARGET_SHMEDIA)
#define HAVE_mshflo_l_di (TARGET_SHMEDIA)
#define HAVE_concat_v2sf (TARGET_SHMEDIA)
#define HAVE_ashlv2si3 (TARGET_SHMEDIA)
#define HAVE_ashlv4hi3 (TARGET_SHMEDIA)
#define HAVE_lshrv2si3 (TARGET_SHMEDIA)
#define HAVE_lshrv4hi3 (TARGET_SHMEDIA)
#define HAVE_subv2si3 (TARGET_SHMEDIA)
#define HAVE_subv4hi3 (TARGET_SHMEDIA)
#define HAVE_subv2hi3 (TARGET_SHMEDIA)
#define HAVE_sssubv2si3 (TARGET_SHMEDIA)
#define HAVE_ussubv8qi3 (TARGET_SHMEDIA)
#define HAVE_sssubv4hi3 (TARGET_SHMEDIA)
#define HAVE_fcosa_s (TARGET_SHMEDIA)
#define HAVE_fsina_s (TARGET_SHMEDIA)
#define HAVE_fipr (TARGET_SHMEDIA)
#define HAVE_fsrra_s (TARGET_SHMEDIA)
#define HAVE_ftrv (TARGET_SHMEDIA)
#define HAVE_ldhi_l (TARGET_SHMEDIA32)
#define HAVE_ldhi_q (TARGET_SHMEDIA32)
#define HAVE_ldlo_l (TARGET_SHMEDIA32)
#define HAVE_ldlo_q (TARGET_SHMEDIA32)
#define HAVE_sthi_l (TARGET_SHMEDIA32)
#define HAVE_sthi_q (TARGET_SHMEDIA32)
#define HAVE_stlo_l (TARGET_SHMEDIA32)
#define HAVE_stlo_q (TARGET_SHMEDIA32)
#define HAVE_ldhi_l64 (TARGET_SHMEDIA64)
#define HAVE_ldhi_q64 (TARGET_SHMEDIA64)
#define HAVE_ldlo_l64 (TARGET_SHMEDIA64)
#define HAVE_ldlo_q64 (TARGET_SHMEDIA64)
#define HAVE_sthi_l64 (TARGET_SHMEDIA64)
#define HAVE_sthi_q64 (TARGET_SHMEDIA64)
#define HAVE_stlo_l64 (TARGET_SHMEDIA64)
#define HAVE_stlo_q64 (TARGET_SHMEDIA64)
#define HAVE_nsb (TARGET_SHMEDIA)
#define HAVE_nsbsi (TARGET_SHMEDIA)
#define HAVE_nsbdi (TARGET_SHMEDIA)
#define HAVE_byterev (TARGET_SHMEDIA)
#define HAVE_prefetch_m2a (TARGET_SH2A)
#define HAVE_alloco_i (TARGET_SHMEDIA32)
#define HAVE_stack_protect_set_si (!TARGET_SHMEDIA)
#define HAVE_stack_protect_set_si_media (TARGET_SHMEDIA)
#define HAVE_stack_protect_set_di_media (TARGET_SHMEDIA64)
#define HAVE_stack_protect_test_si (!TARGET_SHMEDIA)
#define HAVE_stack_protect_test_si_media (TARGET_SHMEDIA)
#define HAVE_stack_protect_test_di_media (TARGET_SHMEDIA64)
#define HAVE_atomic_compare_and_swapqi_soft (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_atomic_compare_and_swaphi_soft (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_atomic_compare_and_swapsi_soft (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_atomic_addqi_soft (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_atomic_subqi_soft (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_atomic_orqi_soft (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_atomic_xorqi_soft (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_atomic_andqi_soft (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_atomic_addhi_soft (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_atomic_subhi_soft (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_atomic_orhi_soft (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_atomic_xorhi_soft (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_atomic_andhi_soft (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_atomic_addsi_soft (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_atomic_subsi_soft (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_atomic_orsi_soft (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_atomic_xorsi_soft (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_atomic_andsi_soft (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_atomic_fetch_nandqi_soft (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_atomic_fetch_nandhi_soft (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_atomic_fetch_nandsi_soft (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_atomic_add_fetchqi_soft (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_atomic_sub_fetchqi_soft (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_atomic_or_fetchqi_soft (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_atomic_xor_fetchqi_soft (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_atomic_and_fetchqi_soft (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_atomic_add_fetchhi_soft (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_atomic_sub_fetchhi_soft (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_atomic_or_fetchhi_soft (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_atomic_xor_fetchhi_soft (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_atomic_and_fetchhi_soft (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_atomic_add_fetchsi_soft (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_atomic_sub_fetchsi_soft (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_atomic_or_fetchsi_soft (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_atomic_xor_fetchsi_soft (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_atomic_and_fetchsi_soft (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_atomic_nand_fetchqi_soft (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_atomic_nand_fetchhi_soft (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_atomic_nand_fetchsi_soft (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_cbranchsi4 1
#define HAVE_cbranchdi4 (TARGET_CBRANCHDI4 || TARGET_SH2 || TARGET_SHMEDIA)
#define HAVE_movdicc (TARGET_SHMEDIA)
#define HAVE_movsicc (TARGET_SHMEDIA || TARGET_PRETEND_CMOVE)
#define HAVE_movqicc (TARGET_SHMEDIA)
#define HAVE_adddi3 1
#define HAVE_addsi3 1
#define HAVE_subdi3 1
#define HAVE_subsi3 1
#define HAVE_udivsi3_i4_media (TARGET_SHMEDIA_FPU)
#define HAVE_udivsi3 1
#define HAVE_divsi3_i4_media (TARGET_SHMEDIA_FPU)
#define HAVE_divsi3 1
#define HAVE_divsi_inv_m0 (TARGET_SHMEDIA)
#define HAVE_mulhisi3 (TARGET_SH1)
#define HAVE_umulhisi3 (TARGET_SH1)
#define HAVE_mulsi3_call (TARGET_SH1)
#define HAVE_mulsi3 (TARGET_SH1)
#define HAVE_mulsidi3 (TARGET_SH2 || TARGET_SHMEDIA)
#define HAVE_umulsidi3 (TARGET_SH2 || TARGET_SHMEDIA)
#define HAVE_smulsi3_highpart (TARGET_SH2)
#define HAVE_umulsi3_highpart (TARGET_SH2)
#define HAVE_andsi3 1
#define HAVE_iorsi3 1
#define HAVE_xorsi3 1
#define HAVE_rotldi3 (TARGET_SHMEDIA)
#define HAVE_rotrdi3 (TARGET_SHMEDIA)
#define HAVE_rotlsi3 (TARGET_SH1)
#define HAVE_rotlhi3 (TARGET_SH1)
#define HAVE_ashlsi3 1
#define HAVE_ashlhi3 (TARGET_SH1)
#define HAVE_ashrsi2_16 (TARGET_SH1)
#define HAVE_ashrsi2_31 (TARGET_SH1)
#define HAVE_ashrsi3 1
#define HAVE_lshrsi3 1
#define HAVE_ashldi3_std (TARGET_SH1 && INTVAL (operands[2]) < 32)
#define HAVE_ashldi3 1
#define HAVE_lshrdi3 1
#define HAVE_ashrdi3 1
#define HAVE_negdi2 1
#define HAVE_one_cmpldi2 (TARGET_SHMEDIA)
#define HAVE_zero_extendhisi2 1
#define HAVE_zero_extendqisi2 1
#define HAVE_extendhisi2 1
#define HAVE_extendqisi2 1
#define HAVE_push (TARGET_SH1 && ! TARGET_SH5)
#define HAVE_pop (TARGET_SH1 && ! TARGET_SH5)
#define HAVE_push_e (TARGET_SH1 && ! TARGET_SH5)
#define HAVE_push_4 (TARGET_SH1 && ! TARGET_SH5)
#define HAVE_pop_e (TARGET_SH1 && ! TARGET_SH5)
#define HAVE_pop_4 (TARGET_SH1 && ! TARGET_SH5)
#define HAVE_push_fpscr (TARGET_SH2E)
#define HAVE_pop_fpscr (TARGET_SH2E)
#define HAVE_movsi_const (TARGET_SHMEDIA && reload_completed \
   && MOVI_SHORI_BASE_OPERAND_P (operands[1]))
#define HAVE_movsi_const_16bit (TARGET_SHMEDIA && flag_pic && reload_completed \
   && GET_CODE (operands[1]) == SYMBOL_REF)
#define HAVE_movsi 1
#define HAVE_ic_invalidate_line (TARGET_HARD_SH4 || TARGET_SH5)
#define HAVE_initialize_trampoline (TARGET_SHCOMPACT)
#define HAVE_movqi 1
#define HAVE_reload_inqi (TARGET_SHMEDIA)
#define HAVE_movhi 1
#define HAVE_reload_inhi (TARGET_SHMEDIA)
#define HAVE_movdi_const (TARGET_SHMEDIA64 && reload_completed \
   && MOVI_SHORI_BASE_OPERAND_P (operands[1]))
#define HAVE_movdi_const_32bit (TARGET_SHMEDIA32 && reload_completed \
   && MOVI_SHORI_BASE_OPERAND_P (operands[1]))
#define HAVE_movdi_const_16bit (TARGET_SHMEDIA && flag_pic && reload_completed \
   && GET_CODE (operands[1]) == SYMBOL_REF)
#define HAVE_movdi 1
#define HAVE_reload_indf__frn (TARGET_SH1)
#define HAVE_reload_outdf__RnFRm (TARGET_SH1)
#define HAVE_movdf 1
#define HAVE_movv2sf (TARGET_SHMEDIA_FPU)
#define HAVE_addv2sf3 (TARGET_SHMEDIA_FPU)
#define HAVE_subv2sf3 (TARGET_SHMEDIA_FPU)
#define HAVE_mulv2sf3 (TARGET_SHMEDIA_FPU)
#define HAVE_divv2sf3 (TARGET_SHMEDIA_FPU)
#define HAVE_movv4sf (TARGET_SHMEDIA_FPU)
#define HAVE_movv16sf (TARGET_SHMEDIA_FPU)
#define HAVE_movsf 1
#define HAVE_reload_insf__frn (TARGET_SH1)
#define HAVE_reload_insi__i_fpul (TARGET_SH1)
#define HAVE_ptabs (TARGET_SHMEDIA)
#define HAVE_cbranchint4_media (TARGET_SHMEDIA)
#define HAVE_cbranchfp4_media (TARGET_SHMEDIA)
#define HAVE_cmpun_sdf 1
#define HAVE_cmpuneq_sdf 1
#define HAVE_doloop_end (TARGET_SH2 && !optimize_size)
#define HAVE_jump 1
#define HAVE_call 1
#define HAVE_call_pop (TARGET_SHCOMPACT)
#define HAVE_call_value 1
#define HAVE_sibcall 1
#define HAVE_sibcall_value 1
#define HAVE_call_value_pop (TARGET_SHCOMPACT)
#define HAVE_sibcall_epilogue 1
#define HAVE_indirect_jump 1
#define HAVE_untyped_call ((TARGET_SH2E || TARGET_SH2A) || TARGET_SHMEDIA)
#define HAVE_GOTaddr2picreg 1
#define HAVE_builtin_setjmp_receiver (flag_pic)
#define HAVE_call_site (TARGET_SH1)
#define HAVE_sym_label2reg (TARGET_SH1)
#define HAVE_symGOT_load 1
#define HAVE_sym2GOT 1
#define HAVE_symGOT2reg 1
#define HAVE_symGOTPLT2reg 1
#define HAVE_sym2GOTOFF 1
#define HAVE_symGOTOFF2reg 1
#define HAVE_symPLT_label2reg (TARGET_SH1)
#define HAVE_sym2PIC 1
#define HAVE_sym2DTPOFF 1
#define HAVE_symDTPOFF2reg 1
#define HAVE_sym2GOTTPOFF 1
#define HAVE_sym2TPOFF 1
#define HAVE_symTPOFF2reg 1
#define HAVE_casesi 1
#define HAVE_casesi_0 (TARGET_SH1)
#define HAVE_return (reload_completed && ! sh_need_epilogue ())
#define HAVE_shcompact_return_tramp (TARGET_SHCOMPACT \
   && (crtl->args.info.call_cookie & CALL_COOKIE_RET_TRAMP (1)))
#define HAVE_return_media (TARGET_SHMEDIA && reload_completed)
#define HAVE_prologue 1
#define HAVE_epilogue 1
#define HAVE_eh_return 1
#define HAVE_cstore4_media (TARGET_SHMEDIA)
#define HAVE_cstoresi4 (TARGET_SH1 || TARGET_SHMEDIA)
#define HAVE_cstoredi4 (TARGET_SH2 || TARGET_SHMEDIA)
#define HAVE_sunle (TARGET_SH1_SOFTFP)
#define HAVE_movnegt 1
#define HAVE_cstoresf4 (TARGET_SH2E || TARGET_SHMEDIA_FPU)
#define HAVE_cstoredf4 ((TARGET_SH4 || TARGET_SH2A_DOUBLE) || TARGET_SHMEDIA_FPU)
#define HAVE_align_2 1
#define HAVE_align_4 1
#define HAVE_movmemsi (TARGET_SH1 && ! TARGET_SH5)
#define HAVE_cmpstrsi (TARGET_HARD_SH4)
#define HAVE_movpsi ((TARGET_SH4 || TARGET_SH2A_DOUBLE))
#define HAVE_addsf3 (TARGET_SH2E || (TARGET_SH3 && TARGET_OSFP) || TARGET_SHMEDIA_FPU)
#define HAVE_subsf3 (TARGET_SH2E || (TARGET_SH3 && TARGET_OSFP) || TARGET_SHMEDIA_FPU)
#define HAVE_mulsf3 (TARGET_SH2E || (TARGET_SH3 && TARGET_OSFP) || TARGET_SHMEDIA_FPU)
#define HAVE_divsf3 (TARGET_SH2E || TARGET_SHMEDIA_FPU)
#define HAVE_floatsisf2 (TARGET_SH2E || TARGET_SHMEDIA_FPU)
#define HAVE_fix_truncsfsi2 (TARGET_SH2E || TARGET_SHMEDIA_FPU)
#define HAVE_cbranchsf4 (TARGET_SH2E || TARGET_SHMEDIA_FPU)
#define HAVE_negsf2 (TARGET_SH2E || TARGET_SHMEDIA_FPU)
#define HAVE_sqrtsf2 (TARGET_SH3E || TARGET_SHMEDIA_FPU)
#define HAVE_sinsf2 (TARGET_SH4A_FP && flag_unsafe_math_optimizations)
#define HAVE_cossf2 (TARGET_SH4A_FP && flag_unsafe_math_optimizations)
#define HAVE_sindf2 (TARGET_SH4A_FP && ! TARGET_FPU_SINGLE && flag_unsafe_math_optimizations)
#define HAVE_cosdf2 (TARGET_SH4A_FP && ! TARGET_FPU_SINGLE && flag_unsafe_math_optimizations)
#define HAVE_abssf2 (TARGET_SH2E || TARGET_SHMEDIA_FPU)
#define HAVE_adddf3 (TARGET_FPU_DOUBLE || (TARGET_SH3 && TARGET_OSFP))
#define HAVE_adddf3_i3_wrap (TARGET_SH3)
#define HAVE_subdf3 ((TARGET_SH4 || TARGET_SH2A_DOUBLE) || TARGET_SHMEDIA_FPU)
#define HAVE_muldf3 (TARGET_FPU_DOUBLE || (TARGET_SH3 && TARGET_OSFP))
#define HAVE_muldf3_i3_wrap (TARGET_SH3)
#define HAVE_divdf3 ((TARGET_SH4 || TARGET_SH2A_DOUBLE) || TARGET_SHMEDIA_FPU)
#define HAVE_floatsidf2 ((TARGET_SH4 || TARGET_SH2A_DOUBLE) || TARGET_SHMEDIA_FPU)
#define HAVE_fix_truncdfsi2 ((TARGET_SH4 || TARGET_SH2A_DOUBLE) || TARGET_SHMEDIA_FPU)
#define HAVE_cbranchdf4 ((TARGET_SH4 || TARGET_SH2A_DOUBLE) || TARGET_SHMEDIA_FPU)
#define HAVE_negdf2 ((TARGET_SH4 || TARGET_SH2A_DOUBLE) || TARGET_SHMEDIA_FPU)
#define HAVE_sqrtdf2 ((TARGET_SH4 || TARGET_SH2A_DOUBLE) || TARGET_SHMEDIA_FPU)
#define HAVE_absdf2 ((TARGET_SH4 || TARGET_SH2A_DOUBLE) || TARGET_SHMEDIA_FPU)
#define HAVE_extendsfdf2 (TARGET_FPU_DOUBLE || (TARGET_SH3 && TARGET_OSFP) || TARGET_SHMEDIA_FPU)
#define HAVE_truncdfsf2 (TARGET_FPU_DOUBLE || (TARGET_SH3 && TARGET_OSFP) || TARGET_SHMEDIA_FPU)
#define HAVE_insv (TARGET_SH1 && ! TARGET_LITTLE_ENDIAN)
#define HAVE_extv (TARGET_SH4A_ARCH || TARGET_SH2A)
#define HAVE_extzv (TARGET_SH4A_ARCH || TARGET_SH2A)
#define HAVE_lrintsfsi2 ((TARGET_SH4 || TARGET_SH2A_SINGLE) && !optimize_size)
#define HAVE_lroundsfsi2 ((TARGET_SH4 || TARGET_SH2A_SINGLE) && !optimize_size)
#define HAVE_movv8qi (TARGET_SHMEDIA)
#define HAVE_movv2hi (TARGET_SHMEDIA)
#define HAVE_movv4hi (TARGET_SHMEDIA)
#define HAVE_movv2si (TARGET_SHMEDIA)
#define HAVE_mextr1 (TARGET_SHMEDIA)
#define HAVE_mextr2 (TARGET_SHMEDIA)
#define HAVE_mextr3 (TARGET_SHMEDIA)
#define HAVE_mextr4 (TARGET_SHMEDIA)
#define HAVE_mextr5 (TARGET_SHMEDIA)
#define HAVE_mextr6 (TARGET_SHMEDIA)
#define HAVE_mextr7 (TARGET_SHMEDIA)
#define HAVE_mmacfx_wl (TARGET_SHMEDIA)
#define HAVE_mmacnfx_wl (TARGET_SHMEDIA)
#define HAVE_mmulhi_wl (TARGET_SHMEDIA)
#define HAVE_mmullo_wl (TARGET_SHMEDIA)
#define HAVE_mmulsum_wq (TARGET_SHMEDIA)
#define HAVE_mperm_w (TARGET_SHMEDIA)
#define HAVE_msad_ubq (TARGET_SHMEDIA)
#define HAVE_mshfhi_b (TARGET_SHMEDIA)
#define HAVE_mshflo_b (TARGET_SHMEDIA)
#define HAVE_mshfhi_l (TARGET_SHMEDIA)
#define HAVE_mshflo_l (TARGET_SHMEDIA)
#define HAVE_mshfhi_w (TARGET_SHMEDIA)
#define HAVE_mshflo_w (TARGET_SHMEDIA)
#define HAVE_ffsdi2 (TARGET_SHMEDIA)
#define HAVE_ffssi2 (TARGET_SHMEDIA)
#define HAVE_prefetch (TARGET_SH2A || ((TARGET_HARD_SH4 || TARGET_SH5) \
   && (TARGET_SHMEDIA || !TARGET_VXWORKS_RTP)))
#define HAVE_stack_protect_set 1
#define HAVE_stack_protect_test 1
#define HAVE_sync_compare_and_swapqi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_compare_and_swaphi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_compare_and_swapsi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_addqi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_subqi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_orqi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_xorqi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_andqi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_addhi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_subhi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_orhi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_xorhi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_andhi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_addsi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_subsi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_orsi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_xorsi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_andsi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_old_addqi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_old_subqi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_old_orqi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_old_xorqi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_old_andqi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_old_addhi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_old_subhi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_old_orhi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_old_xorhi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_old_andhi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_old_addsi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_old_subsi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_old_orsi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_old_xorsi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_old_andsi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_fetch_nandqi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_fetch_nandhi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_fetch_nandsi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_old_fetch_nandqi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_old_fetch_nandhi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_old_fetch_nandsi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_add_fetchqi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_sub_fetchqi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_or_fetchqi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_xor_fetchqi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_and_fetchqi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_add_fetchhi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_sub_fetchhi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_or_fetchhi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_xor_fetchhi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_and_fetchhi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_add_fetchsi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_sub_fetchsi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_or_fetchsi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_xor_fetchsi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_and_fetchsi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_old_add_fetchqi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_old_sub_fetchqi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_old_or_fetchqi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_old_xor_fetchqi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_old_and_fetchqi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_old_add_fetchhi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_old_sub_fetchhi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_old_or_fetchhi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_old_xor_fetchhi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_old_and_fetchhi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_old_add_fetchsi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_old_sub_fetchsi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_old_or_fetchsi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_old_xor_fetchsi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_old_and_fetchsi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_nand_fetchqi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_nand_fetchhi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_nand_fetchsi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_old_nand_fetchqi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_old_nand_fetchhi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
#define HAVE_sync_old_nand_fetchsi (TARGET_SOFT_ATOMIC && !TARGET_SHMEDIA)
extern rtx        gen_tstsi2                            (rtx, rtx);
extern rtx        gen_cmpeqsi_t                         (rtx, rtx);
extern rtx        gen_fpcmp_i1                          (rtx, rtx);
extern rtx        gen_cmpgtsi_t                         (rtx, rtx);
extern rtx        gen_cmpgesi_t                         (rtx, rtx);
extern rtx        gen_cmpgeusi_t                        (rtx, rtx);
extern rtx        gen_cmpgtusi_t                        (rtx, rtx);
extern rtx        gen_cmpeqdi_t                         (rtx, rtx);
extern rtx        gen_cmpgtdi_t                         (rtx, rtx);
extern rtx        gen_cmpgedi_t                         (rtx, rtx);
extern rtx        gen_cmpgeudi_t                        (rtx, rtx);
extern rtx        gen_cmpgtudi_t                        (rtx, rtx);
extern rtx        gen_cmpeqsi_media                     (rtx, rtx, rtx);
extern rtx        gen_cmpeqdi_media                     (rtx, rtx, rtx);
extern rtx        gen_cmpgtsi_media                     (rtx, rtx, rtx);
extern rtx        gen_cmpgtdi_media                     (rtx, rtx, rtx);
extern rtx        gen_cmpgtusi_media                    (rtx, rtx, rtx);
extern rtx        gen_cmpgtudi_media                    (rtx, rtx, rtx);
extern rtx        gen_movdicc_false                     (rtx, rtx, rtx, rtx);
extern rtx        gen_movdicc_true                      (rtx, rtx, rtx, rtx);
extern rtx        gen_movsicc_false                     (rtx, rtx, rtx, rtx);
extern rtx        gen_movsicc_true                      (rtx, rtx, rtx, rtx);
extern rtx        gen_adddi3z_media                     (rtx, rtx, rtx);
extern rtx        gen_adddi3_compact                    (rtx, rtx, rtx);
extern rtx        gen_addc                              (rtx, rtx, rtx);
extern rtx        gen_addc1                             (rtx, rtx, rtx);
extern rtx        gen_addsi3_media                      (rtx, rtx, rtx);
extern rtx        gen_addsidi3_media                    (rtx, rtx, rtx);
extern rtx        gen_subdisi3_media                    (rtx, rtx, rtx);
extern rtx        gen_subdi3_compact                    (rtx, rtx, rtx);
extern rtx        gen_subc                              (rtx, rtx, rtx);
extern rtx        gen_subc1                             (rtx, rtx, rtx);
extern rtx        gen_mov_neg_si_t                      (rtx);
extern rtx        gen_use_sfunc_addr                    (rtx);
extern rtx        gen_udivsi3_sh2a                      (rtx, rtx, rtx);
extern rtx        gen_udivsi3_i1                        (rtx, rtx);
extern rtx        gen_udivsi3_i1_media                  (rtx, rtx);
extern rtx        gen_udivsi3_i4                        (rtx, rtx);
extern rtx        gen_udivsi3_i4_single                 (rtx, rtx);
extern rtx        gen_udivsi3_i4_int                    (rtx, rtx);
extern rtx        gen_divsi3_sh2a                       (rtx, rtx, rtx);
extern rtx        gen_divsi3_i1                         (rtx, rtx);
extern rtx        gen_divsi3_i1_media                   (rtx, rtx);
extern rtx        gen_divsi3_media_2                    (rtx, rtx);
extern rtx        gen_divsi_inv_call                    (rtx, rtx, rtx, rtx);
extern rtx        gen_divsi3_i4                         (rtx, rtx);
extern rtx        gen_divsi3_i4_single                  (rtx, rtx);
extern rtx        gen_divsi3_i4_int                     (rtx, rtx);
extern rtx        gen_divsi_inv_qitable                 (rtx, rtx, rtx);
extern rtx        gen_divsi_inv_hitable                 (rtx, rtx, rtx);
extern rtx        gen_divsi_inv_m1                      (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_divsi_inv_m2                      (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_divsi_inv_m3                      (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_divsi_inv_m1_3                    (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_divsi_inv20                       (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_divsi_inv_fp                      (rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_umulhisi3_i                       (rtx, rtx);
extern rtx        gen_mulhisi3_i                        (rtx, rtx);
extern rtx        gen_mul_r                             (rtx, rtx, rtx);
extern rtx        gen_mul_l                             (rtx, rtx);
extern rtx        gen_mulr03                            (rtx, rtx, rtx);
extern rtx        gen_mulsidi3_i                        (rtx, rtx);
extern rtx        gen_mulsidi3_media                    (rtx, rtx, rtx);
extern rtx        gen_mulsidi3_compact                  (rtx, rtx, rtx);
extern rtx        gen_umulsidi3_i                       (rtx, rtx);
extern rtx        gen_umulsidi3_media                   (rtx, rtx, rtx);
extern rtx        gen_umulsidi3_compact                 (rtx, rtx, rtx);
extern rtx        gen_smulsi3_highpart_i                (rtx, rtx);
extern rtx        gen_umulsi3_highpart_i                (rtx, rtx);
extern rtx        gen_muldi3                            (rtx, rtx, rtx);
extern rtx        gen_anddi3                            (rtx, rtx, rtx);
extern rtx        gen_andcsi3                           (rtx, rtx, rtx);
extern rtx        gen_andcdi3                           (rtx, rtx, rtx);
extern rtx        gen_iordi3                            (rtx, rtx, rtx);
extern rtx        gen_xorsi3_movrt                      (rtx);
extern rtx        gen_xordi3                            (rtx, rtx, rtx);
extern rtx        gen_rotldi3_mextr                     (rtx, rtx, rtx);
extern rtx        gen_rotrdi3_mextr                     (rtx, rtx, rtx);
extern rtx        gen_rotlsi3_1                         (rtx, rtx);
extern rtx        gen_rotlsi3_31                        (rtx, rtx);
extern rtx        gen_rotlsi3_16                        (rtx, rtx);
extern rtx        gen_rotlhi3_8                         (rtx, rtx);
extern rtx        gen_ashlsi3_sh2a                      (rtx, rtx, rtx);
extern rtx        gen_ashlsi3_k                         (rtx, rtx, rtx);
extern rtx        gen_ashlsi3_std                       (rtx, rtx, rtx);
extern rtx        gen_ashlhi3_k                         (rtx, rtx, rtx);
extern rtx        gen_ashlsi3_n                         (rtx, rtx, rtx);
extern rtx        gen_ashlsi3_media                     (rtx, rtx, rtx);
extern rtx        gen_ashrsi3_sh2a                      (rtx, rtx, rtx);
extern rtx        gen_ashrsi3_k                         (rtx, rtx, rtx);
extern rtx        gen_ashlsi_c                          (rtx, rtx);
extern rtx        gen_ashrsi3_d                         (rtx, rtx, rtx);
extern rtx        gen_ashrsi3_n                         (rtx, rtx);
extern rtx        gen_ashrsi3_media                     (rtx, rtx, rtx);
extern rtx        gen_lshrsi3_sh2a                      (rtx, rtx, rtx);
extern rtx        gen_lshrsi3_d                         (rtx, rtx, rtx);
extern rtx        gen_lshrsi3_m                         (rtx, rtx, rtx);
extern rtx        gen_lshrsi3_k                         (rtx, rtx, rtx);
extern rtx        gen_lshrsi3_n                         (rtx, rtx, rtx);
extern rtx        gen_lshrsi3_media                     (rtx, rtx, rtx);
extern rtx        gen_ashldi3_k                         (rtx, rtx);
extern rtx        gen_ashldi3_media                     (rtx, rtx, rtx);
extern rtx        gen_lshrdi3_k                         (rtx, rtx);
extern rtx        gen_lshrdi3_media                     (rtx, rtx, rtx);
extern rtx        gen_ashrdi3_k                         (rtx, rtx);
extern rtx        gen_ashrdi3_media                     (rtx, rtx, rtx);
extern rtx        gen_ashrdisi3_media_high              (rtx, rtx, rtx);
extern rtx        gen_ashrdisi3_media_opaque            (rtx, rtx, rtx);
extern rtx        gen_and_shl_scratch                   (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_shl_sext_ext                      (rtx, rtx, rtx, rtx);
extern rtx        gen_shl_sext_sub                      (rtx, rtx, rtx, rtx);
extern rtx        gen_xtrct_left                        (rtx, rtx, rtx);
extern rtx        gen_xtrct_right                       (rtx, rtx, rtx);
extern rtx        gen_negc                              (rtx, rtx);
extern rtx        gen_negsi2                            (rtx, rtx);
extern rtx        gen_one_cmplsi2                       (rtx, rtx);
extern rtx        gen_cneg                              (rtx, rtx, rtx);
extern rtx        gen_zero_extendsidi2                  (rtx, rtx);
extern rtx        gen_zero_extendhidi2                  (rtx, rtx);
extern rtx        gen_zero_extendqidi2                  (rtx, rtx);
extern rtx        gen_zero_extendqihi2                  (rtx, rtx);
extern rtx        gen_extendsidi2                       (rtx, rtx);
extern rtx        gen_extendhidi2                       (rtx, rtx);
extern rtx        gen_extendqidi2                       (rtx, rtx);
extern rtx        gen_extendqihi2                       (rtx, rtx);
extern rtx        gen_truncdisi2                        (rtx, rtx);
extern rtx        gen_truncdihi2                        (rtx, rtx);
extern rtx        gen_truncdiqi2                        (rtx, rtx);
extern rtx        gen_push_fpul                         (void);
extern rtx        gen_pop_fpul                          (void);
extern rtx        gen_pop_fpul2                         (rtx);
extern rtx        gen_clrt                              (void);
extern rtx        gen_sett                              (void);
extern rtx        gen_movsi_i                           (rtx, rtx);
extern rtx        gen_movsi_ie                          (rtx, rtx);
extern rtx        gen_movsi_i_lowpart                   (rtx, rtx);
extern rtx        gen_load_ra                           (rtx, rtx);
extern rtx        gen_ic_invalidate_line_i              (rtx, rtx);
extern rtx        gen_ic_invalidate_line_sh4a           (rtx);
extern rtx        gen_ic_invalidate_line_media          (rtx);
extern rtx        gen_ic_invalidate_line_compact        (rtx, rtx);
extern rtx        gen_initialize_trampoline_compact     (rtx, rtx);
extern rtx        gen_movqi_i                           (rtx, rtx);
extern rtx        gen_movhi_i                           (rtx, rtx);
extern rtx        gen_shori_media                       (rtx, rtx, rtx);
extern rtx        gen_movdf_media                       (rtx, rtx);
extern rtx        gen_movdf_media_nofpu                 (rtx, rtx);
extern rtx        gen_movdf_k                           (rtx, rtx);
extern rtx        gen_movdf_i4                          (rtx, rtx, rtx);
extern rtx        gen_movv2sf_i                         (rtx, rtx);
extern rtx        gen_movsf_media                       (rtx, rtx);
extern rtx        gen_movsf_media_nofpu                 (rtx, rtx);
extern rtx        gen_movsf_i                           (rtx, rtx);
extern rtx        gen_movsf_ie                          (rtx, rtx, rtx);
extern rtx        gen_mov_nop                           (rtx);
extern rtx        gen_branch_true                       (rtx);
extern rtx        gen_branch_false                      (rtx);
extern rtx        gen_block_branch_redirect             (rtx);
extern rtx        gen_indirect_jump_scratch             (rtx, rtx);
extern rtx        gen_stuff_delay_slot                  (rtx, rtx);
extern rtx        gen_doloop_end_split                  (rtx, rtx, rtx);
extern rtx        gen_jump_compact                      (rtx);
extern rtx        gen_jump_media                        (rtx);
extern rtx        gen_force_mode_for_call               (void);
extern rtx        gen_calli                             (rtx, rtx);
extern rtx        gen_calli_tbr_rel                     (rtx, rtx);
extern rtx        gen_calli_pcrel                       (rtx, rtx, rtx);
extern rtx        gen_call_pcrel                        (rtx, rtx);
extern rtx        gen_call_compact                      (rtx, rtx, rtx);
extern rtx        gen_call_compact_rettramp             (rtx, rtx, rtx);
extern rtx        gen_call_media                        (rtx, rtx);
extern rtx        gen_call_valuei                       (rtx, rtx, rtx);
extern rtx        gen_call_valuei_tbr_rel               (rtx, rtx, rtx);
extern rtx        gen_call_valuei_pcrel                 (rtx, rtx, rtx, rtx);
extern rtx        gen_call_value_pcrel                  (rtx, rtx, rtx);
extern rtx        gen_call_value_compact                (rtx, rtx, rtx, rtx);
extern rtx        gen_call_value_compact_rettramp       (rtx, rtx, rtx, rtx);
extern rtx        gen_call_value_media                  (rtx, rtx, rtx);
extern rtx        gen_call_pop_compact                  (rtx, rtx, rtx, rtx);
extern rtx        gen_call_pop_compact_rettramp         (rtx, rtx, rtx, rtx);
extern rtx        gen_sibcalli                          (rtx, rtx);
extern rtx        gen_sibcalli_pcrel                    (rtx, rtx, rtx);
extern rtx        gen_sibcalli_thunk                    (rtx, rtx);
extern rtx        gen_sibcall_pcrel                     (rtx, rtx);
extern rtx        gen_sibcall_compact                   (rtx, rtx, rtx);
extern rtx        gen_sibcall_media                     (rtx, rtx);
extern rtx        gen_sibcall_valuei                    (rtx, rtx, rtx);
extern rtx        gen_sibcall_valuei_pcrel              (rtx, rtx, rtx, rtx);
extern rtx        gen_sibcall_value_pcrel               (rtx, rtx, rtx);
extern rtx        gen_sibcall_value_compact             (rtx, rtx, rtx, rtx);
extern rtx        gen_sibcall_value_media               (rtx, rtx, rtx);
extern rtx        gen_call_value_pop_compact            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_call_value_pop_compact_rettramp   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_indirect_jump_compact             (rtx);
extern rtx        gen_casesi_jump_1                     (rtx, rtx);
extern rtx        gen_casesi_jump_2                     (rtx, rtx, rtx);
extern rtx        gen_casesi_jump_media                 (rtx, rtx);
extern rtx        gen_dup_db_insn                       (void);
extern rtx        gen_dect                              (rtx, rtx);
extern rtx        gen_nop                               (void);
extern rtx        gen_mova                              (rtx);
extern rtx        gen_mova_const                        (rtx);
extern rtx        gen_ptrel_si                          (rtx, rtx, rtx);
extern rtx        gen_ptrel_di                          (rtx, rtx, rtx);
extern rtx        gen_chk_guard_add                     (rtx, rtx);
extern rtx        gen_tls_global_dynamic                (rtx, rtx);
extern rtx        gen_tls_local_dynamic                 (rtx, rtx);
extern rtx        gen_tls_initial_exec                  (rtx, rtx);
extern rtx        gen_load_gbr                          (rtx);
extern rtx        gen_casesi_worker_0                   (rtx, rtx, rtx);
extern rtx        gen_casesi_worker_1                   (rtx, rtx, rtx);
extern rtx        gen_casesi_worker_2                   (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_casesi_shift_media                (rtx, rtx, rtx);
extern rtx        gen_casesi_load_media                 (rtx, rtx, rtx, rtx);
static inline rtx gen_trap                              (void);
static inline rtx
gen_trap(void)
{
  return 0;
}
extern rtx        gen_shcompact_return_tramp_i          (void);
extern rtx        gen_return_media_i                    (rtx);
extern rtx        gen_return_media_rte                  (void);
extern rtx        gen_shcompact_preserve_incoming_args  (rtx);
extern rtx        gen_shcompact_incoming_args           (void);
extern rtx        gen_shmedia_save_restore_regs_compact (rtx);
extern rtx        gen_eh_set_ra_si                      (rtx);
extern rtx        gen_eh_set_ra_di                      (rtx);
extern rtx        gen_blockage                          (void);
extern rtx        gen_movml_push_banked                 (rtx);
extern rtx        gen_movml_pop_banked                  (rtx);
extern rtx        gen_movt                              (rtx);
extern rtx        gen_consttable_2                      (rtx, rtx);
extern rtx        gen_consttable_4                      (rtx, rtx);
extern rtx        gen_consttable_8                      (rtx, rtx);
extern rtx        gen_consttable_sf                     (rtx, rtx);
extern rtx        gen_consttable_df                     (rtx, rtx);
extern rtx        gen_align_log                         (rtx);
extern rtx        gen_consttable_end                    (void);
extern rtx        gen_consttable_window_end             (rtx);
extern rtx        gen_block_move_real                   (rtx);
extern rtx        gen_block_lump_real                   (rtx);
extern rtx        gen_block_move_real_i4                (rtx);
extern rtx        gen_block_lump_real_i4                (rtx);
extern rtx        gen_cmpstr_t                          (rtx, rtx);
extern rtx        gen_rotcr_t                           (rtx);
extern rtx        gen_fpu_switch                        (rtx, rtx);
extern rtx        gen_toggle_sz                         (void);
extern rtx        gen_toggle_pr                         (void);
extern rtx        gen_unary_sf_op                       (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_binary_sf_op0                     (rtx, rtx, rtx, rtx);
extern rtx        gen_binary_sf_op1                     (rtx, rtx, rtx, rtx);
static inline rtx gen_addsf3_i3                         (rtx, rtx);
static inline rtx
gen_addsf3_i3(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_addsf3_i                          (rtx, rtx, rtx, rtx);
static inline rtx gen_subsf3_i3                         (rtx, rtx);
static inline rtx
gen_subsf3_i3(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_subsf3_i                          (rtx, rtx, rtx, rtx);
extern rtx        gen_mulsf3_ie                         (rtx, rtx, rtx);
extern rtx        gen_mulsf3_i4                         (rtx, rtx, rtx, rtx);
static inline rtx gen_mulsf3_i3                         (rtx, rtx);
static inline rtx
gen_mulsf3_i3(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_mac_media                         (rtx, rtx, rtx, rtx);
extern rtx        gen_divsf3_i                          (rtx, rtx, rtx, rtx);
extern rtx        gen_floatdisf2                        (rtx, rtx);
extern rtx        gen_floatsisf2_i4                     (rtx, rtx, rtx);
extern rtx        gen_fix_truncsfdi2                    (rtx, rtx);
extern rtx        gen_fix_truncsfsi2_i4                 (rtx, rtx, rtx);
extern rtx        gen_cmpgtsf_t                         (rtx, rtx);
extern rtx        gen_cmpnesf_i1                        (rtx, rtx);
extern rtx        gen_cmpgtsf_i1                        (rtx, rtx);
extern rtx        gen_cmpunltsf_i1                      (rtx, rtx);
extern rtx        gen_cmpeqsf_i1_finite                 (rtx, rtx);
extern rtx        gen_cmplesf_i1_finite                 (rtx, rtx);
extern rtx        gen_cmpunsf_i1                        (rtx, rtx, rtx);
extern rtx        gen_cmpuneqsf_i1                      (rtx, rtx, rtx);
extern rtx        gen_movcc_fp_ne                       (rtx, rtx);
extern rtx        gen_movcc_fp_gt                       (rtx, rtx);
extern rtx        gen_movcc_fp_unlt                     (rtx, rtx);
extern rtx        gen_cmpeqsf_t                         (rtx, rtx);
extern rtx        gen_ieee_ccmpeqsf_t                   (rtx, rtx);
extern rtx        gen_cmpgtsf_t_i4                      (rtx, rtx, rtx);
extern rtx        gen_cmpeqsf_t_i4                      (rtx, rtx, rtx);
extern rtx        gen_cmpeqsf_media                     (rtx, rtx, rtx);
extern rtx        gen_cmpgtsf_media                     (rtx, rtx, rtx);
extern rtx        gen_cmpgesf_media                     (rtx, rtx, rtx);
extern rtx        gen_cmpunsf_media                     (rtx, rtx, rtx);
extern rtx        gen_negsf2_i                          (rtx, rtx, rtx);
extern rtx        gen_sqrtsf2_i                         (rtx, rtx, rtx);
extern rtx        gen_rsqrtsf2                          (rtx, rtx, rtx, rtx);
extern rtx        gen_fsca                              (rtx, rtx, rtx, rtx);
extern rtx        gen_abssf2_i                          (rtx, rtx, rtx);
static inline rtx gen_abssc2_i3                         (rtx, rtx);
static inline rtx
gen_abssc2_i3(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_adddf3_i                          (rtx, rtx, rtx, rtx);
extern rtx        gen_adddf3_i3                         (rtx);
extern rtx        gen_subdf3_i                          (rtx, rtx, rtx, rtx);
extern rtx        gen_muldf3_i                          (rtx, rtx, rtx, rtx);
extern rtx        gen_muldf3_i3                         (rtx);
extern rtx        gen_divdf3_i                          (rtx, rtx, rtx, rtx);
extern rtx        gen_floatdidf2                        (rtx, rtx);
extern rtx        gen_floatsidf2_i                      (rtx, rtx, rtx);
extern rtx        gen_fix_truncdfdi2                    (rtx, rtx);
extern rtx        gen_fix_truncdfsi2_i                  (rtx, rtx, rtx);
extern rtx        gen_cmpnedf_i1                        (rtx, rtx);
extern rtx        gen_cmpgtdf_i1                        (rtx, rtx);
extern rtx        gen_cmpunltdf_i1                      (rtx, rtx);
extern rtx        gen_cmpeqdf_i1_finite                 (rtx, rtx);
extern rtx        gen_cmpundf_i1                        (rtx, rtx, rtx);
extern rtx        gen_cmpuneqdf_i1                      (rtx, rtx, rtx);
extern rtx        gen_cmpgtdf_t                         (rtx, rtx, rtx);
extern rtx        gen_cmpeqdf_t                         (rtx, rtx, rtx);
extern rtx        gen_cmpeqdf_media                     (rtx, rtx, rtx);
extern rtx        gen_cmpgtdf_media                     (rtx, rtx, rtx);
extern rtx        gen_cmpgedf_media                     (rtx, rtx, rtx);
extern rtx        gen_cmpundf_media                     (rtx, rtx, rtx);
extern rtx        gen_negdf2_i                          (rtx, rtx, rtx);
extern rtx        gen_sqrtdf2_i                         (rtx, rtx, rtx);
extern rtx        gen_absdf2_i                          (rtx, rtx, rtx);
extern rtx        gen_extendsfdf2_i4                    (rtx, rtx, rtx);
extern rtx        gen_extendsfdf2_i1                    (rtx, rtx);
extern rtx        gen_extendsfdf2_i1_r0                 (rtx);
extern rtx        gen_extendsfdf2_i2e                   (rtx, rtx);
extern rtx        gen_extendsfdf2_i2e_r0                (rtx);
extern rtx        gen_truncdfsf2_i4                     (rtx, rtx, rtx);
extern rtx        gen_truncdfsf2_i1                     (rtx, rtx);
extern rtx        gen_truncdfsf2_i2e                    (rtx, rtx);
extern rtx        gen_movua                             (rtx, rtx);
extern rtx        gen_bclr_m2a                          (rtx, rtx);
extern rtx        gen_bclrmem_m2a                       (rtx, rtx);
extern rtx        gen_bset_m2a                          (rtx, rtx);
extern rtx        gen_bsetmem_m2a                       (rtx, rtx);
extern rtx        gen_bst_m2a                           (rtx, rtx);
extern rtx        gen_bld_m2a                           (rtx, rtx);
extern rtx        gen_bldsign_m2a                       (rtx, rtx);
extern rtx        gen_bld_reg                           (rtx, rtx);
extern rtx        gen_band_m2a                          (rtx, rtx);
extern rtx        gen_bandreg_m2a                       (rtx, rtx, rtx, rtx);
extern rtx        gen_bor_m2a                           (rtx, rtx);
extern rtx        gen_borreg_m2a                        (rtx, rtx, rtx, rtx);
extern rtx        gen_bxor_m2a                          (rtx, rtx);
extern rtx        gen_bxorreg_m2a                       (rtx, rtx, rtx, rtx);
extern rtx        gen_sp_switch_1                       (rtx);
extern rtx        gen_sp_switch_2                       (void);
extern rtx        gen_movv8qi_i                         (rtx, rtx);
extern rtx        gen_movv2hi_i                         (rtx, rtx);
extern rtx        gen_movv4hi_i                         (rtx, rtx);
extern rtx        gen_movv2si_i                         (rtx, rtx);
extern rtx        gen_absv2si2                          (rtx, rtx);
extern rtx        gen_absv4hi2                          (rtx, rtx);
extern rtx        gen_addv2si3                          (rtx, rtx, rtx);
extern rtx        gen_addv4hi3                          (rtx, rtx, rtx);
extern rtx        gen_addv2hi3                          (rtx, rtx, rtx);
extern rtx        gen_ssaddv2si3                        (rtx, rtx, rtx);
extern rtx        gen_usaddv8qi3                        (rtx, rtx, rtx);
extern rtx        gen_ssaddv4hi3                        (rtx, rtx, rtx);
extern rtx        gen_negcmpeqv8qi                      (rtx, rtx, rtx);
extern rtx        gen_negcmpeqv2si                      (rtx, rtx, rtx);
extern rtx        gen_negcmpeqv4hi                      (rtx, rtx, rtx);
extern rtx        gen_negcmpgtuv8qi                     (rtx, rtx, rtx);
extern rtx        gen_negcmpgtv2si                      (rtx, rtx, rtx);
extern rtx        gen_negcmpgtv4hi                      (rtx, rtx, rtx);
extern rtx        gen_mcmv                              (rtx, rtx, rtx, rtx);
extern rtx        gen_mcnvs_lw                          (rtx, rtx, rtx);
extern rtx        gen_mcnvs_wb                          (rtx, rtx, rtx);
extern rtx        gen_mcnvs_wub                         (rtx, rtx, rtx);
extern rtx        gen_mextr_rl                          (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mmacfx_wl_i                       (rtx, rtx, rtx, rtx);
extern rtx        gen_mmacnfx_wl_i                      (rtx, rtx, rtx, rtx);
extern rtx        gen_mulv2si3                          (rtx, rtx, rtx);
extern rtx        gen_mulv4hi3                          (rtx, rtx, rtx);
extern rtx        gen_mmulfx_l                          (rtx, rtx, rtx);
extern rtx        gen_mmulfx_w                          (rtx, rtx, rtx);
extern rtx        gen_mmulfxrp_w                        (rtx, rtx, rtx);
extern rtx        gen_mmul23_wl                         (rtx, rtx, rtx);
extern rtx        gen_mmul01_wl                         (rtx, rtx, rtx);
extern rtx        gen_mmulsum_wq_i                      (rtx, rtx, rtx, rtx);
extern rtx        gen_mperm_w_little                    (rtx, rtx, rtx);
extern rtx        gen_mperm_w_big                       (rtx, rtx, rtx);
extern rtx        gen_mperm_w0                          (rtx, rtx);
extern rtx        gen_msad_ubq_i                        (rtx, rtx, rtx, rtx);
extern rtx        gen_mshalds_l                         (rtx, rtx, rtx);
extern rtx        gen_mshalds_w                         (rtx, rtx, rtx);
extern rtx        gen_ashrv2si3                         (rtx, rtx, rtx);
extern rtx        gen_ashrv4hi3                         (rtx, rtx, rtx);
extern rtx        gen_mshards_q                         (rtx, rtx, rtx);
extern rtx        gen_mshf4_b                           (rtx, rtx, rtx);
extern rtx        gen_mshf0_b                           (rtx, rtx, rtx);
extern rtx        gen_mshf4_l                           (rtx, rtx, rtx);
extern rtx        gen_mshf0_l                           (rtx, rtx, rtx);
extern rtx        gen_mshf4_w                           (rtx, rtx, rtx);
extern rtx        gen_mshf0_w                           (rtx, rtx, rtx);
extern rtx        gen_mshflo_w_x                        (rtx, rtx, rtx);
extern rtx        gen_mshfhi_l_di                       (rtx, rtx, rtx);
extern rtx        gen_mshflo_l_di                       (rtx, rtx, rtx);
extern rtx        gen_concat_v2sf                       (rtx, rtx, rtx);
extern rtx        gen_ashlv2si3                         (rtx, rtx, rtx);
extern rtx        gen_ashlv4hi3                         (rtx, rtx, rtx);
extern rtx        gen_lshrv2si3                         (rtx, rtx, rtx);
extern rtx        gen_lshrv4hi3                         (rtx, rtx, rtx);
extern rtx        gen_subv2si3                          (rtx, rtx, rtx);
extern rtx        gen_subv4hi3                          (rtx, rtx, rtx);
extern rtx        gen_subv2hi3                          (rtx, rtx, rtx);
extern rtx        gen_sssubv2si3                        (rtx, rtx, rtx);
extern rtx        gen_ussubv8qi3                        (rtx, rtx, rtx);
extern rtx        gen_sssubv4hi3                        (rtx, rtx, rtx);
extern rtx        gen_fcosa_s                           (rtx, rtx);
extern rtx        gen_fsina_s                           (rtx, rtx);
extern rtx        gen_fipr                              (rtx, rtx, rtx);
extern rtx        gen_fsrra_s                           (rtx, rtx);
extern rtx        gen_ftrv                              (rtx, rtx, rtx);
extern rtx        gen_ldhi_l                            (rtx, rtx);
extern rtx        gen_ldhi_q                            (rtx, rtx);
extern rtx        gen_ldlo_l                            (rtx, rtx);
extern rtx        gen_ldlo_q                            (rtx, rtx);
extern rtx        gen_sthi_l                            (rtx, rtx);
extern rtx        gen_sthi_q                            (rtx, rtx);
extern rtx        gen_stlo_l                            (rtx, rtx);
extern rtx        gen_stlo_q                            (rtx, rtx);
extern rtx        gen_ldhi_l64                          (rtx, rtx);
extern rtx        gen_ldhi_q64                          (rtx, rtx);
extern rtx        gen_ldlo_l64                          (rtx, rtx);
extern rtx        gen_ldlo_q64                          (rtx, rtx);
extern rtx        gen_sthi_l64                          (rtx, rtx);
extern rtx        gen_sthi_q64                          (rtx, rtx);
extern rtx        gen_stlo_l64                          (rtx, rtx);
extern rtx        gen_stlo_q64                          (rtx, rtx);
extern rtx        gen_nsb                               (rtx, rtx);
extern rtx        gen_nsbsi                             (rtx, rtx);
extern rtx        gen_nsbdi                             (rtx, rtx);
extern rtx        gen_byterev                           (rtx, rtx);
extern rtx        gen_prefetch_m2a                      (rtx, rtx, rtx);
extern rtx        gen_alloco_i                          (rtx);
extern rtx        gen_stack_protect_set_si              (rtx, rtx);
extern rtx        gen_stack_protect_set_si_media        (rtx, rtx);
extern rtx        gen_stack_protect_set_di_media        (rtx, rtx);
extern rtx        gen_stack_protect_test_si             (rtx, rtx);
extern rtx        gen_stack_protect_test_si_media       (rtx, rtx, rtx);
extern rtx        gen_stack_protect_test_di_media       (rtx, rtx, rtx);
extern rtx        gen_atomic_compare_and_swapqi_soft    (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_compare_and_swaphi_soft    (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_compare_and_swapsi_soft    (rtx, rtx, rtx, rtx);
extern rtx        gen_atomic_addqi_soft                 (rtx, rtx, rtx);
extern rtx        gen_atomic_subqi_soft                 (rtx, rtx, rtx);
extern rtx        gen_atomic_orqi_soft                  (rtx, rtx, rtx);
extern rtx        gen_atomic_xorqi_soft                 (rtx, rtx, rtx);
extern rtx        gen_atomic_andqi_soft                 (rtx, rtx, rtx);
extern rtx        gen_atomic_addhi_soft                 (rtx, rtx, rtx);
extern rtx        gen_atomic_subhi_soft                 (rtx, rtx, rtx);
extern rtx        gen_atomic_orhi_soft                  (rtx, rtx, rtx);
extern rtx        gen_atomic_xorhi_soft                 (rtx, rtx, rtx);
extern rtx        gen_atomic_andhi_soft                 (rtx, rtx, rtx);
extern rtx        gen_atomic_addsi_soft                 (rtx, rtx, rtx);
extern rtx        gen_atomic_subsi_soft                 (rtx, rtx, rtx);
extern rtx        gen_atomic_orsi_soft                  (rtx, rtx, rtx);
extern rtx        gen_atomic_xorsi_soft                 (rtx, rtx, rtx);
extern rtx        gen_atomic_andsi_soft                 (rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_nandqi_soft          (rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_nandhi_soft          (rtx, rtx, rtx);
extern rtx        gen_atomic_fetch_nandsi_soft          (rtx, rtx, rtx);
extern rtx        gen_atomic_add_fetchqi_soft           (rtx, rtx, rtx);
extern rtx        gen_atomic_sub_fetchqi_soft           (rtx, rtx, rtx);
extern rtx        gen_atomic_or_fetchqi_soft            (rtx, rtx, rtx);
extern rtx        gen_atomic_xor_fetchqi_soft           (rtx, rtx, rtx);
extern rtx        gen_atomic_and_fetchqi_soft           (rtx, rtx, rtx);
extern rtx        gen_atomic_add_fetchhi_soft           (rtx, rtx, rtx);
extern rtx        gen_atomic_sub_fetchhi_soft           (rtx, rtx, rtx);
extern rtx        gen_atomic_or_fetchhi_soft            (rtx, rtx, rtx);
extern rtx        gen_atomic_xor_fetchhi_soft           (rtx, rtx, rtx);
extern rtx        gen_atomic_and_fetchhi_soft           (rtx, rtx, rtx);
extern rtx        gen_atomic_add_fetchsi_soft           (rtx, rtx, rtx);
extern rtx        gen_atomic_sub_fetchsi_soft           (rtx, rtx, rtx);
extern rtx        gen_atomic_or_fetchsi_soft            (rtx, rtx, rtx);
extern rtx        gen_atomic_xor_fetchsi_soft           (rtx, rtx, rtx);
extern rtx        gen_atomic_and_fetchsi_soft           (rtx, rtx, rtx);
extern rtx        gen_atomic_nand_fetchqi_soft          (rtx, rtx, rtx);
extern rtx        gen_atomic_nand_fetchhi_soft          (rtx, rtx, rtx);
extern rtx        gen_atomic_nand_fetchsi_soft          (rtx, rtx, rtx);
extern rtx        gen_cbranchsi4                        (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchdi4                        (rtx, rtx, rtx, rtx);
extern rtx        gen_movdicc                           (rtx, rtx, rtx, rtx);
extern rtx        gen_movsicc                           (rtx, rtx, rtx, rtx);
extern rtx        gen_movqicc                           (rtx, rtx, rtx, rtx);
extern rtx        gen_adddi3                            (rtx, rtx, rtx);
extern rtx        gen_addsi3                            (rtx, rtx, rtx);
extern rtx        gen_subdi3                            (rtx, rtx, rtx);
extern rtx        gen_subsi3                            (rtx, rtx, rtx);
extern rtx        gen_udivsi3_i4_media                  (rtx, rtx, rtx);
extern rtx        gen_udivsi3                           (rtx, rtx, rtx);
extern rtx        gen_divsi3_i4_media                   (rtx, rtx, rtx);
extern rtx        gen_divsi3                            (rtx, rtx, rtx);
extern rtx        gen_divsi_inv_m0                      (rtx, rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_mulhisi3                          (rtx, rtx, rtx);
extern rtx        gen_umulhisi3                         (rtx, rtx, rtx);
extern rtx        gen_mulsi3_call                       (rtx, rtx, rtx, rtx);
extern rtx        gen_mulsi3                            (rtx, rtx, rtx);
extern rtx        gen_mulsidi3                          (rtx, rtx, rtx);
extern rtx        gen_umulsidi3                         (rtx, rtx, rtx);
extern rtx        gen_smulsi3_highpart                  (rtx, rtx, rtx);
extern rtx        gen_umulsi3_highpart                  (rtx, rtx, rtx);
extern rtx        gen_andsi3                            (rtx, rtx, rtx);
extern rtx        gen_iorsi3                            (rtx, rtx, rtx);
extern rtx        gen_xorsi3                            (rtx, rtx, rtx);
extern rtx        gen_rotldi3                           (rtx, rtx, rtx);
extern rtx        gen_rotrdi3                           (rtx, rtx, rtx);
extern rtx        gen_rotlsi3                           (rtx, rtx, rtx);
extern rtx        gen_rotlhi3                           (rtx, rtx, rtx);
extern rtx        gen_ashlsi3                           (rtx, rtx, rtx);
extern rtx        gen_ashlhi3                           (rtx, rtx, rtx);
extern rtx        gen_ashrsi2_16                        (rtx, rtx);
extern rtx        gen_ashrsi2_31                        (rtx, rtx);
extern rtx        gen_ashrsi3                           (rtx, rtx, rtx);
extern rtx        gen_lshrsi3                           (rtx, rtx, rtx);
extern rtx        gen_ashldi3_std                       (rtx, rtx, rtx);
extern rtx        gen_ashldi3                           (rtx, rtx, rtx);
extern rtx        gen_lshrdi3                           (rtx, rtx, rtx);
extern rtx        gen_ashrdi3                           (rtx, rtx, rtx);
extern rtx        gen_negdi2                            (rtx, rtx);
extern rtx        gen_one_cmpldi2                       (rtx, rtx);
extern rtx        gen_zero_extendhisi2                  (rtx, rtx);
extern rtx        gen_zero_extendqisi2                  (rtx, rtx);
extern rtx        gen_extendhisi2                       (rtx, rtx);
extern rtx        gen_extendqisi2                       (rtx, rtx);
extern rtx        gen_push                              (rtx);
extern rtx        gen_pop                               (rtx);
extern rtx        gen_push_e                            (rtx);
extern rtx        gen_push_4                            (rtx);
extern rtx        gen_pop_e                             (rtx);
extern rtx        gen_pop_4                             (rtx);
extern rtx        gen_push_fpscr                        (void);
extern rtx        gen_pop_fpscr                         (void);
extern rtx        gen_movsi_const                       (rtx, rtx);
extern rtx        gen_movsi_const_16bit                 (rtx, rtx);
extern rtx        gen_movsi                             (rtx, rtx);
extern rtx        gen_ic_invalidate_line                (rtx);
extern rtx        gen_initialize_trampoline             (rtx, rtx, rtx);
extern rtx        gen_movqi                             (rtx, rtx);
extern rtx        gen_reload_inqi                       (rtx, rtx, rtx);
extern rtx        gen_movhi                             (rtx, rtx);
extern rtx        gen_reload_inhi                       (rtx, rtx, rtx);
extern rtx        gen_movdi_const                       (rtx, rtx);
extern rtx        gen_movdi_const_32bit                 (rtx, rtx);
extern rtx        gen_movdi_const_16bit                 (rtx, rtx);
extern rtx        gen_movdi                             (rtx, rtx);
extern rtx        gen_reload_indf__frn                  (rtx, rtx, rtx);
extern rtx        gen_reload_outdf__RnFRm               (rtx, rtx, rtx);
extern rtx        gen_movdf                             (rtx, rtx);
extern rtx        gen_movv2sf                           (rtx, rtx);
extern rtx        gen_addv2sf3                          (rtx, rtx, rtx);
extern rtx        gen_subv2sf3                          (rtx, rtx, rtx);
extern rtx        gen_mulv2sf3                          (rtx, rtx, rtx);
extern rtx        gen_divv2sf3                          (rtx, rtx, rtx);
extern rtx        gen_movv4sf                           (rtx, rtx);
extern rtx        gen_movv16sf                          (rtx, rtx);
extern rtx        gen_movsf                             (rtx, rtx);
extern rtx        gen_reload_insf__frn                  (rtx, rtx, rtx);
extern rtx        gen_reload_insi__i_fpul               (rtx, rtx, rtx);
extern rtx        gen_ptabs                             (rtx, rtx);
extern rtx        gen_cbranchint4_media                 (rtx, rtx, rtx, rtx);
extern rtx        gen_cbranchfp4_media                  (rtx, rtx, rtx, rtx);
extern rtx        gen_cmpun_sdf                         (rtx, rtx);
extern rtx        gen_cmpuneq_sdf                       (rtx, rtx);
extern rtx        gen_doloop_end                        (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_jump                              (rtx);
#define GEN_CALL(A, B, C, D) gen_call ((A), (B), (C))
extern rtx        gen_call                              (rtx, rtx, rtx);
#define GEN_CALL_POP(A, B, C, D) gen_call_pop ((A), (B), (C), (D))
extern rtx        gen_call_pop                          (rtx, rtx, rtx, rtx);
#define GEN_CALL_VALUE(A, B, C, D, E) gen_call_value ((A), (B), (C), (D))
extern rtx        gen_call_value                        (rtx, rtx, rtx, rtx);
#define GEN_SIBCALL(A, B, C, D) gen_sibcall ((A), (B), (C))
extern rtx        gen_sibcall                           (rtx, rtx, rtx);
#define GEN_SIBCALL_VALUE(A, B, C, D, E) gen_sibcall_value ((A), (B), (C), (D))
extern rtx        gen_sibcall_value                     (rtx, rtx, rtx, rtx);
#define GEN_CALL_VALUE_POP(A, B, C, D, E) gen_call_value_pop ((A), (B), (C), (D), (E))
extern rtx        gen_call_value_pop                    (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_sibcall_epilogue                  (void);
extern rtx        gen_indirect_jump                     (rtx);
extern rtx        gen_untyped_call                      (rtx, rtx, rtx);
extern rtx        gen_GOTaddr2picreg                    (void);
static inline rtx gen_vxworks_picreg                    (rtx, rtx);
static inline rtx
gen_vxworks_picreg(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_builtin_setjmp_receiver           (rtx);
extern rtx        gen_call_site                         (void);
extern rtx        gen_sym_label2reg                     (rtx, rtx, rtx);
extern rtx        gen_symGOT_load                       (rtx, rtx);
extern rtx        gen_sym2GOT                           (rtx);
extern rtx        gen_symGOT2reg                        (rtx, rtx);
extern rtx        gen_symGOTPLT2reg                     (rtx, rtx);
extern rtx        gen_sym2GOTOFF                        (rtx);
extern rtx        gen_symGOTOFF2reg                     (rtx, rtx);
extern rtx        gen_symPLT_label2reg                  (rtx, rtx, rtx);
extern rtx        gen_sym2PIC                           (rtx);
extern rtx        gen_sym2DTPOFF                        (rtx);
extern rtx        gen_symDTPOFF2reg                     (rtx, rtx, rtx);
extern rtx        gen_sym2GOTTPOFF                      (rtx);
extern rtx        gen_sym2TPOFF                         (rtx);
extern rtx        gen_symTPOFF2reg                      (rtx, rtx);
extern rtx        gen_casesi                            (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_casesi_0                          (rtx, rtx, rtx, rtx, rtx);
extern rtx        gen_return                            (void);
extern rtx        gen_shcompact_return_tramp            (void);
extern rtx        gen_return_media                      (void);
extern rtx        gen_prologue                          (void);
extern rtx        gen_epilogue                          (void);
extern rtx        gen_eh_return                         (rtx);
extern rtx        gen_cstore4_media                     (rtx, rtx, rtx, rtx);
extern rtx        gen_cstoresi4                         (rtx, rtx, rtx, rtx);
extern rtx        gen_cstoredi4                         (rtx, rtx, rtx, rtx);
extern rtx        gen_sunle                             (rtx);
extern rtx        gen_movnegt                           (rtx);
extern rtx        gen_cstoresf4                         (rtx, rtx, rtx, rtx);
extern rtx        gen_cstoredf4                         (rtx, rtx, rtx, rtx);
extern rtx        gen_align_2                           (void);
extern rtx        gen_align_4                           (void);
extern rtx        gen_movmemsi                          (rtx, rtx, rtx, rtx);
extern rtx        gen_cmpstrsi                          (rtx, rtx, rtx, rtx);
extern rtx        gen_movpsi                            (rtx, rtx);
extern rtx        gen_addsf3                            (rtx, rtx, rtx);
extern rtx        gen_subsf3                            (rtx, rtx, rtx);
extern rtx        gen_mulsf3                            (rtx, rtx, rtx);
extern rtx        gen_divsf3                            (rtx, rtx, rtx);
extern rtx        gen_floatsisf2                        (rtx, rtx);
extern rtx        gen_fix_truncsfsi2                    (rtx, rtx);
extern rtx        gen_cbranchsf4                        (rtx, rtx, rtx, rtx);
extern rtx        gen_negsf2                            (rtx, rtx);
extern rtx        gen_sqrtsf2                           (rtx, rtx);
extern rtx        gen_sinsf2                            (rtx, rtx);
extern rtx        gen_cossf2                            (rtx, rtx);
extern rtx        gen_sindf2                            (rtx, rtx);
extern rtx        gen_cosdf2                            (rtx, rtx);
extern rtx        gen_abssf2                            (rtx, rtx);
static inline rtx gen_abssc2                            (rtx, rtx);
static inline rtx
gen_abssc2(rtx ARG_UNUSED (a), rtx ARG_UNUSED (b))
{
  return 0;
}
extern rtx        gen_adddf3                            (rtx, rtx, rtx);
extern rtx        gen_adddf3_i3_wrap                    (rtx, rtx);
extern rtx        gen_subdf3                            (rtx, rtx, rtx);
extern rtx        gen_muldf3                            (rtx, rtx, rtx);
extern rtx        gen_muldf3_i3_wrap                    (rtx, rtx);
extern rtx        gen_divdf3                            (rtx, rtx, rtx);
extern rtx        gen_floatsidf2                        (rtx, rtx);
extern rtx        gen_fix_truncdfsi2                    (rtx, rtx);
extern rtx        gen_cbranchdf4                        (rtx, rtx, rtx, rtx);
extern rtx        gen_negdf2                            (rtx, rtx);
extern rtx        gen_sqrtdf2                           (rtx, rtx);
extern rtx        gen_absdf2                            (rtx, rtx);
extern rtx        gen_extendsfdf2                       (rtx, rtx);
extern rtx        gen_truncdfsf2                        (rtx, rtx);
extern rtx        gen_insv                              (rtx, rtx, rtx, rtx);
extern rtx        gen_extv                              (rtx, rtx, rtx, rtx);
extern rtx        gen_extzv                             (rtx, rtx, rtx, rtx);
extern rtx        gen_lrintsfsi2                        (rtx, rtx);
extern rtx        gen_lroundsfsi2                       (rtx, rtx);
extern rtx        gen_movv8qi                           (rtx, rtx);
extern rtx        gen_movv2hi                           (rtx, rtx);
extern rtx        gen_movv4hi                           (rtx, rtx);
extern rtx        gen_movv2si                           (rtx, rtx);
extern rtx        gen_mextr1                            (rtx, rtx, rtx);
extern rtx        gen_mextr2                            (rtx, rtx, rtx);
extern rtx        gen_mextr3                            (rtx, rtx, rtx);
extern rtx        gen_mextr4                            (rtx, rtx, rtx);
extern rtx        gen_mextr5                            (rtx, rtx, rtx);
extern rtx        gen_mextr6                            (rtx, rtx, rtx);
extern rtx        gen_mextr7                            (rtx, rtx, rtx);
extern rtx        gen_mmacfx_wl                         (rtx, rtx, rtx, rtx);
extern rtx        gen_mmacnfx_wl                        (rtx, rtx, rtx, rtx);
extern rtx        gen_mmulhi_wl                         (rtx, rtx, rtx);
extern rtx        gen_mmullo_wl                         (rtx, rtx, rtx);
extern rtx        gen_mmulsum_wq                        (rtx, rtx, rtx, rtx);
extern rtx        gen_mperm_w                           (rtx, rtx, rtx);
extern rtx        gen_msad_ubq                          (rtx, rtx, rtx, rtx);
extern rtx        gen_mshfhi_b                          (rtx, rtx, rtx);
extern rtx        gen_mshflo_b                          (rtx, rtx, rtx);
extern rtx        gen_mshfhi_l                          (rtx, rtx, rtx);
extern rtx        gen_mshflo_l                          (rtx, rtx, rtx);
extern rtx        gen_mshfhi_w                          (rtx, rtx, rtx);
extern rtx        gen_mshflo_w                          (rtx, rtx, rtx);
extern rtx        gen_ffsdi2                            (rtx, rtx);
extern rtx        gen_ffssi2                            (rtx, rtx);
extern rtx        gen_prefetch                          (rtx, rtx, rtx);
extern rtx        gen_stack_protect_set                 (rtx, rtx);
extern rtx        gen_stack_protect_test                (rtx, rtx, rtx);
extern rtx        gen_sync_compare_and_swapqi           (rtx, rtx, rtx, rtx);
extern rtx        gen_sync_compare_and_swaphi           (rtx, rtx, rtx, rtx);
extern rtx        gen_sync_compare_and_swapsi           (rtx, rtx, rtx, rtx);
extern rtx        gen_sync_addqi                        (rtx, rtx, rtx);
extern rtx        gen_sync_subqi                        (rtx, rtx, rtx);
extern rtx        gen_sync_orqi                         (rtx, rtx, rtx);
extern rtx        gen_sync_xorqi                        (rtx, rtx, rtx);
extern rtx        gen_sync_andqi                        (rtx, rtx, rtx);
extern rtx        gen_sync_addhi                        (rtx, rtx, rtx);
extern rtx        gen_sync_subhi                        (rtx, rtx, rtx);
extern rtx        gen_sync_orhi                         (rtx, rtx, rtx);
extern rtx        gen_sync_xorhi                        (rtx, rtx, rtx);
extern rtx        gen_sync_andhi                        (rtx, rtx, rtx);
extern rtx        gen_sync_addsi                        (rtx, rtx, rtx);
extern rtx        gen_sync_subsi                        (rtx, rtx, rtx);
extern rtx        gen_sync_orsi                         (rtx, rtx, rtx);
extern rtx        gen_sync_xorsi                        (rtx, rtx, rtx);
extern rtx        gen_sync_andsi                        (rtx, rtx, rtx);
extern rtx        gen_sync_old_addqi                    (rtx, rtx, rtx, rtx);
extern rtx        gen_sync_old_subqi                    (rtx, rtx, rtx, rtx);
extern rtx        gen_sync_old_orqi                     (rtx, rtx, rtx, rtx);
extern rtx        gen_sync_old_xorqi                    (rtx, rtx, rtx, rtx);
extern rtx        gen_sync_old_andqi                    (rtx, rtx, rtx, rtx);
extern rtx        gen_sync_old_addhi                    (rtx, rtx, rtx, rtx);
extern rtx        gen_sync_old_subhi                    (rtx, rtx, rtx, rtx);
extern rtx        gen_sync_old_orhi                     (rtx, rtx, rtx, rtx);
extern rtx        gen_sync_old_xorhi                    (rtx, rtx, rtx, rtx);
extern rtx        gen_sync_old_andhi                    (rtx, rtx, rtx, rtx);
extern rtx        gen_sync_old_addsi                    (rtx, rtx, rtx, rtx);
extern rtx        gen_sync_old_subsi                    (rtx, rtx, rtx, rtx);
extern rtx        gen_sync_old_orsi                     (rtx, rtx, rtx, rtx);
extern rtx        gen_sync_old_xorsi                    (rtx, rtx, rtx, rtx);
extern rtx        gen_sync_old_andsi                    (rtx, rtx, rtx, rtx);
extern rtx        gen_sync_fetch_nandqi                 (rtx, rtx, rtx);
extern rtx        gen_sync_fetch_nandhi                 (rtx, rtx, rtx);
extern rtx        gen_sync_fetch_nandsi                 (rtx, rtx, rtx);
extern rtx        gen_sync_old_fetch_nandqi             (rtx, rtx, rtx, rtx);
extern rtx        gen_sync_old_fetch_nandhi             (rtx, rtx, rtx, rtx);
extern rtx        gen_sync_old_fetch_nandsi             (rtx, rtx, rtx, rtx);
extern rtx        gen_sync_add_fetchqi                  (rtx, rtx, rtx);
extern rtx        gen_sync_sub_fetchqi                  (rtx, rtx, rtx);
extern rtx        gen_sync_or_fetchqi                   (rtx, rtx, rtx);
extern rtx        gen_sync_xor_fetchqi                  (rtx, rtx, rtx);
extern rtx        gen_sync_and_fetchqi                  (rtx, rtx, rtx);
extern rtx        gen_sync_add_fetchhi                  (rtx, rtx, rtx);
extern rtx        gen_sync_sub_fetchhi                  (rtx, rtx, rtx);
extern rtx        gen_sync_or_fetchhi                   (rtx, rtx, rtx);
extern rtx        gen_sync_xor_fetchhi                  (rtx, rtx, rtx);
extern rtx        gen_sync_and_fetchhi                  (rtx, rtx, rtx);
extern rtx        gen_sync_add_fetchsi                  (rtx, rtx, rtx);
extern rtx        gen_sync_sub_fetchsi                  (rtx, rtx, rtx);
extern rtx        gen_sync_or_fetchsi                   (rtx, rtx, rtx);
extern rtx        gen_sync_xor_fetchsi                  (rtx, rtx, rtx);
extern rtx        gen_sync_and_fetchsi                  (rtx, rtx, rtx);
extern rtx        gen_sync_old_add_fetchqi              (rtx, rtx, rtx, rtx);
extern rtx        gen_sync_old_sub_fetchqi              (rtx, rtx, rtx, rtx);
extern rtx        gen_sync_old_or_fetchqi               (rtx, rtx, rtx, rtx);
extern rtx        gen_sync_old_xor_fetchqi              (rtx, rtx, rtx, rtx);
extern rtx        gen_sync_old_and_fetchqi              (rtx, rtx, rtx, rtx);
extern rtx        gen_sync_old_add_fetchhi              (rtx, rtx, rtx, rtx);
extern rtx        gen_sync_old_sub_fetchhi              (rtx, rtx, rtx, rtx);
extern rtx        gen_sync_old_or_fetchhi               (rtx, rtx, rtx, rtx);
extern rtx        gen_sync_old_xor_fetchhi              (rtx, rtx, rtx, rtx);
extern rtx        gen_sync_old_and_fetchhi              (rtx, rtx, rtx, rtx);
extern rtx        gen_sync_old_add_fetchsi              (rtx, rtx, rtx, rtx);
extern rtx        gen_sync_old_sub_fetchsi              (rtx, rtx, rtx, rtx);
extern rtx        gen_sync_old_or_fetchsi               (rtx, rtx, rtx, rtx);
extern rtx        gen_sync_old_xor_fetchsi              (rtx, rtx, rtx, rtx);
extern rtx        gen_sync_old_and_fetchsi              (rtx, rtx, rtx, rtx);
extern rtx        gen_sync_nand_fetchqi                 (rtx, rtx, rtx);
extern rtx        gen_sync_nand_fetchhi                 (rtx, rtx, rtx);
extern rtx        gen_sync_nand_fetchsi                 (rtx, rtx, rtx);
extern rtx        gen_sync_old_nand_fetchqi             (rtx, rtx, rtx, rtx);
extern rtx        gen_sync_old_nand_fetchhi             (rtx, rtx, rtx, rtx);
extern rtx        gen_sync_old_nand_fetchsi             (rtx, rtx, rtx, rtx);

#endif /* GCC_INSN_FLAGS_H */
