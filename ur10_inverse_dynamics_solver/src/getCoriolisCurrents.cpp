/* -------------------------------------------------------------------
 *
 * This module has been developed by the Automatic Control Group
 * of the University of Salerno, Italy.
 *
 * Title:   getCoriolisCurrents.cpp
 * Author:  Antonio Annunziata, Vincenzo Petrone
 * Org.:    UNISA
 * Date:    Jul 7, 2023
 *
 * Refer to the header file for a description of this module.
 *
 * -------------------------------------------------------------------
 */

//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: getCoriolisCurrents.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 14-Jul-2023 11:40:19
//

// Include Files
#include <cmath>
#include "ur10_inverse_dynamics_solver/getCoriolisCurrents.h"

// Function Definitions
//
// getCoriolisCurrents
//     CORIOLIS_CURRENT = getCoriolisCurrents(IN1,IN2)
//
// Arguments    : const double in1[6]
//                const double in2[6]
//                double coriolis_current[6]
// Return Type  : void
//
namespace ur10_inverse_dynamics_solver
{
void getCoriolisCurrents(const double in1[6], const double in2[6], double coriolis_current[6])
{
  double ab_coriolis_current_tmp;
  double b_coriolis_current_tmp;
  double b_coriolis_current_tmp_tmp;
  double b_coriolis_current_tmp_tmp_tmp;
  double c_coriolis_current_tmp;
  double c_coriolis_current_tmp_tmp;
  double c_coriolis_current_tmp_tmp_tmp;
  double coriolis_current_tmp;
  double coriolis_current_tmp_tmp;
  double coriolis_current_tmp_tmp_tmp;
  double ct_idx_158;
  double ct_idx_193;
  double ct_idx_194;
  double ct_idx_195;
  double ct_idx_196;
  double ct_idx_197;
  double ct_idx_198;
  double ct_idx_199;
  double ct_idx_200;
  double ct_idx_202;
  double ct_idx_204;
  double ct_idx_207;
  double ct_idx_208;
  double ct_idx_209;
  double ct_idx_210;
  double ct_idx_211;
  double ct_idx_214;
  double ct_idx_215;
  double ct_idx_218;
  double ct_idx_219;
  double ct_idx_222;
  double ct_idx_224;
  double ct_idx_225;
  double ct_idx_226;
  double ct_idx_227;
  double ct_idx_228;
  double ct_idx_236;
  double ct_idx_253;
  double ct_idx_257;
  double ct_idx_262;
  double ct_idx_265;
  double ct_idx_270;
  double ct_idx_272;
  double ct_idx_274;
  double ct_idx_275;
  double ct_idx_280;
  double ct_idx_282;
  double ct_idx_283;
  double ct_idx_284;
  double ct_idx_285;
  double ct_idx_286;
  double ct_idx_287;
  double ct_idx_290;
  double ct_idx_291;
  double ct_idx_313;
  double d;
  double d1;
  double d10;
  double d100;
  double d101;
  double d102;
  double d103;
  double d104;
  double d105;
  double d106;
  double d107;
  double d108;
  double d109;
  double d11;
  double d110;
  double d111;
  double d112;
  double d113;
  double d114;
  double d115;
  double d116;
  double d117;
  double d118;
  double d119;
  double d12;
  double d120;
  double d121;
  double d122;
  double d123;
  double d124;
  double d125;
  double d126;
  double d127;
  double d128;
  double d129;
  double d13;
  double d130;
  double d131;
  double d132;
  double d133;
  double d134;
  double d135;
  double d136;
  double d137;
  double d138;
  double d139;
  double d14;
  double d140;
  double d141;
  double d142;
  double d143;
  double d144;
  double d145;
  double d146;
  double d147;
  double d148;
  double d149;
  double d15;
  double d150;
  double d151;
  double d152;
  double d153;
  double d154;
  double d155;
  double d156;
  double d157;
  double d158;
  double d159;
  double d16;
  double d160;
  double d161;
  double d162;
  double d163;
  double d164;
  double d165;
  double d166;
  double d167;
  double d168;
  double d169;
  double d17;
  double d170;
  double d171;
  double d172;
  double d173;
  double d174;
  double d175;
  double d176;
  double d177;
  double d178;
  double d179;
  double d18;
  double d180;
  double d181;
  double d182;
  double d183;
  double d184;
  double d185;
  double d186;
  double d187;
  double d188;
  double d189;
  double d19;
  double d190;
  double d191;
  double d192;
  double d193;
  double d194;
  double d195;
  double d196;
  double d197;
  double d198;
  double d199;
  double d2;
  double d20;
  double d200;
  double d201;
  double d202;
  double d203;
  double d204;
  double d205;
  double d206;
  double d207;
  double d208;
  double d209;
  double d21;
  double d210;
  double d211;
  double d212;
  double d213;
  double d214;
  double d215;
  double d216;
  double d217;
  double d218;
  double d219;
  double d22;
  double d220;
  double d221;
  double d222;
  double d223;
  double d224;
  double d225;
  double d226;
  double d227;
  double d228;
  double d229;
  double d23;
  double d230;
  double d231;
  double d232;
  double d233;
  double d234;
  double d235;
  double d236;
  double d237;
  double d238;
  double d239;
  double d24;
  double d240;
  double d241;
  double d242;
  double d243;
  double d244;
  double d245;
  double d246;
  double d247;
  double d248;
  double d249;
  double d25;
  double d250;
  double d251;
  double d252;
  double d253;
  double d254;
  double d255;
  double d256;
  double d257;
  double d258;
  double d259;
  double d26;
  double d260;
  double d261;
  double d262;
  double d263;
  double d264;
  double d265;
  double d266;
  double d267;
  double d268;
  double d269;
  double d27;
  double d270;
  double d271;
  double d272;
  double d273;
  double d274;
  double d275;
  double d276;
  double d277;
  double d278;
  double d279;
  double d28;
  double d280;
  double d281;
  double d282;
  double d283;
  double d284;
  double d285;
  double d286;
  double d287;
  double d288;
  double d289;
  double d29;
  double d290;
  double d291;
  double d292;
  double d293;
  double d294;
  double d295;
  double d296;
  double d297;
  double d298;
  double d299;
  double d3;
  double d30;
  double d300;
  double d301;
  double d302;
  double d303;
  double d304;
  double d305;
  double d306;
  double d307;
  double d308;
  double d309;
  double d31;
  double d310;
  double d311;
  double d312;
  double d313;
  double d314;
  double d315;
  double d316;
  double d317;
  double d318;
  double d319;
  double d32;
  double d320;
  double d321;
  double d322;
  double d323;
  double d324;
  double d325;
  double d326;
  double d327;
  double d328;
  double d329;
  double d33;
  double d330;
  double d331;
  double d332;
  double d333;
  double d334;
  double d335;
  double d336;
  double d337;
  double d338;
  double d339;
  double d34;
  double d340;
  double d341;
  double d342;
  double d343;
  double d344;
  double d345;
  double d346;
  double d347;
  double d348;
  double d349;
  double d35;
  double d350;
  double d351;
  double d352;
  double d353;
  double d354;
  double d355;
  double d356;
  double d357;
  double d358;
  double d359;
  double d36;
  double d360;
  double d361;
  double d362;
  double d363;
  double d364;
  double d365;
  double d366;
  double d367;
  double d368;
  double d369;
  double d37;
  double d370;
  double d371;
  double d372;
  double d373;
  double d374;
  double d375;
  double d376;
  double d377;
  double d378;
  double d379;
  double d38;
  double d380;
  double d381;
  double d382;
  double d383;
  double d384;
  double d385;
  double d386;
  double d387;
  double d388;
  double d389;
  double d39;
  double d390;
  double d391;
  double d392;
  double d393;
  double d394;
  double d395;
  double d396;
  double d397;
  double d398;
  double d399;
  double d4;
  double d40;
  double d400;
  double d401;
  double d402;
  double d403;
  double d404;
  double d405;
  double d406;
  double d407;
  double d408;
  double d409;
  double d41;
  double d410;
  double d42;
  double d43;
  double d44;
  double d45;
  double d46;
  double d47;
  double d48;
  double d49;
  double d5;
  double d50;
  double d51;
  double d52;
  double d53;
  double d54;
  double d55;
  double d56;
  double d57;
  double d58;
  double d59;
  double d6;
  double d60;
  double d61;
  double d62;
  double d63;
  double d64;
  double d65;
  double d66;
  double d67;
  double d68;
  double d69;
  double d7;
  double d70;
  double d71;
  double d72;
  double d73;
  double d74;
  double d75;
  double d76;
  double d77;
  double d78;
  double d79;
  double d8;
  double d80;
  double d81;
  double d82;
  double d83;
  double d84;
  double d85;
  double d86;
  double d87;
  double d88;
  double d89;
  double d9;
  double d90;
  double d91;
  double d92;
  double d93;
  double d94;
  double d95;
  double d96;
  double d97;
  double d98;
  double d99;
  double d_coriolis_current_tmp;
  double d_coriolis_current_tmp_tmp;
  double e_coriolis_current_tmp;
  double e_coriolis_current_tmp_tmp;
  double f_coriolis_current_tmp;
  double f_coriolis_current_tmp_tmp;
  double g_coriolis_current_tmp;
  double g_coriolis_current_tmp_tmp;
  double h_coriolis_current_tmp;
  double h_coriolis_current_tmp_tmp;
  double i_coriolis_current_tmp;
  double i_coriolis_current_tmp_tmp;
  double j_coriolis_current_tmp;
  double j_coriolis_current_tmp_tmp;
  double k_coriolis_current_tmp;
  double k_coriolis_current_tmp_tmp;
  double l_coriolis_current_tmp;
  double l_coriolis_current_tmp_tmp;
  double m_coriolis_current_tmp;
  double m_coriolis_current_tmp_tmp;
  double n_coriolis_current_tmp;
  double n_coriolis_current_tmp_tmp;
  double o_coriolis_current_tmp;
  double p_coriolis_current_tmp;
  double q_coriolis_current_tmp;
  double r_coriolis_current_tmp;
  double s_coriolis_current_tmp;
  double t10;
  double t100;
  double t101;
  double t102;
  double t103;
  double t104;
  double t105;
  double t106;
  double t107;
  double t109;
  double t11;
  double t110;
  double t111;
  double t112;
  double t113;
  double t114;
  double t115;
  double t116;
  double t117;
  double t118;
  double t12;
  double t120;
  double t121;
  double t122;
  double t124;
  double t125;
  double t126;
  double t127;
  double t128;
  double t13;
  double t130;
  double t131;
  double t133;
  double t135;
  double t136;
  double t137;
  double t139;
  double t14;
  double t140;
  double t141;
  double t142;
  double t143;
  double t144;
  double t145;
  double t146;
  double t147;
  double t148;
  double t149;
  double t15;
  double t150;
  double t151;
  double t152;
  double t153;
  double t154;
  double t155;
  double t16;
  double t160;
  double t161;
  double t162;
  double t163;
  double t164;
  double t165;
  double t166;
  double t167;
  double t168;
  double t169;
  double t17;
  double t170;
  double t171;
  double t172;
  double t175;
  double t176;
  double t177;
  double t178;
  double t179;
  double t18;
  double t180;
  double t181;
  double t182;
  double t183;
  double t184;
  double t185;
  double t186;
  double t187;
  double t19;
  double t190;
  double t191;
  double t192;
  double t193;
  double t194;
  double t195;
  double t196;
  double t197;
  double t199;
  double t2;
  double t20;
  double t200;
  double t201;
  double t202;
  double t203;
  double t204;
  double t205;
  double t206;
  double t207;
  double t208;
  double t209;
  double t21;
  double t210;
  double t211;
  double t214;
  double t215;
  double t216;
  double t217;
  double t218;
  double t219;
  double t22;
  double t220;
  double t221;
  double t222;
  double t223;
  double t23;
  double t241;
  double t243;
  double t244;
  double t247;
  double t25;
  double t253;
  double t26;
  double t260;
  double t263;
  double t264;
  double t267;
  double t268;
  double t27;
  double t279;
  double t28;
  double t280;
  double t281;
  double t282;
  double t283;
  double t284;
  double t29;
  double t3;
  double t30;
  double t33;
  double t34;
  double t4;
  double t40;
  double t43;
  double t44;
  double t45;
  double t46;
  double t47;
  double t48;
  double t49;
  double t5;
  double t50;
  double t51;
  double t52;
  double t54;
  double t55;
  double t56;
  double t57;
  double t58;
  double t59;
  double t6;
  double t60;
  double t61;
  double t68;
  double t69;
  double t7;
  double t70;
  double t71;
  double t72;
  double t73;
  double t74;
  double t75;
  double t76;
  double t77;
  double t78;
  double t79;
  double t8;
  double t80;
  double t81;
  double t82;
  double t83;
  double t84;
  double t86;
  double t87;
  double t88;
  double t89;
  double t9;
  double t90;
  double t91;
  double t92;
  double t94;
  double t95;
  double t96;
  double t97;
  double t98;
  double t99;
  double t_coriolis_current_tmp;
  double u_coriolis_current_tmp;
  double v_coriolis_current_tmp;
  double w_coriolis_current_tmp;
  double x_coriolis_current_tmp;
  double y_coriolis_current_tmp;

  //     This function was generated by the Symbolic Math Toolbox version 9.3.
  //     14-Jul-2023 11:23:26
  t2 = std::cos(in1[1]);
  t3 = std::cos(in1[2]);
  t4 = std::cos(in1[3]);
  t5 = std::cos(in1[4]);
  t6 = std::cos(in1[5]);
  t7 = std::sin(in1[1]);
  t8 = std::sin(in1[2]);
  t9 = std::sin(in1[3]);
  t10 = std::sin(in1[4]);
  t11 = std::sin(in1[5]);
  t12 = in1[1] + in1[2];
  t13 = in1[1] + in1[4];
  t14 = in1[2] + in1[3];
  t15 = in1[3] + in1[4];
  t16 = in1[3] + in1[5];
  t17 = in1[4] + in1[5];
  t18 = in2[1] + in2[2];
  t19 = in1[1] * 2.0;
  t20 = in1[2] * 2.0;
  t21 = in1[3] * 2.0;
  t22 = in1[4] * 2.0;
  t23 = in1[5] * 2.0;
  t25 = in2[1] * in2[1];
  t26 = in2[2] * in2[2];
  t27 = in2[3] * in2[3];
  t28 = in2[4] * in2[4];
  t29 = in2[5] * in2[5];
  t30 = std::cos(t19);
  t33 = std::cos(t22);
  t34 = std::cos(t23);
  t40 = std::sin(t19);
  t43 = std::sin(t22);
  t44 = std::sin(t23);
  t45 = std::cos(t13);
  t46 = std::cos(t14);
  t47 = std::cos(t15);
  t48 = std::cos(t16);
  t49 = std::cos(t17);
  t50 = in1[3] + t12;
  t51 = in1[4] + t12;
  t52 = in1[4] + t14;
  t19 = in1[5] + t13;
  t54 = in1[5] + t14;
  t55 = in1[5] + t15;
  t56 = in2[3] + t18;
  t57 = std::sin(t13);
  t58 = std::sin(t14);
  t59 = std::sin(t15);
  t60 = std::sin(t16);
  t61 = std::sin(t17);
  t74 = t12 + t15;
  t75 = t12 + t16;
  t76 = t12 + t17;
  t77 = t14 + t17;
  t84 = in1[1] + t12;
  t86 = in1[4] + t17;
  t87 = t18 * t18;
  t104 = in1[1] - in1[4];
  t105 = in1[3] - in1[4];
  t106 = in1[3] - in1[5];
  t107 = in1[4] - in1[5];
  t109 = t12 * 2.0;
  t110 = t17 * 2.0;
  t116 = t12 - in1[4];
  t117 = t14 - in1[4];
  t118 = t13 - in1[5];
  t120 = t14 - in1[5];
  t121 = t17 - in1[1];
  t122 = t15 - in1[5];
  t16 -= in1[4];
  t124 = t17 - in1[3];
  t137 = t22 - in1[5];
  t243 = t12 - t17;
  t244 = t14 - t17;
  t68 = std::cos(t50);
  t69 = std::cos(t51);
  t70 = std::cos(t52);
  t71 = std::cos(t19);
  t72 = std::cos(t54);
  t73 = std::cos(t55);
  t78 = std::sin(t50);
  t79 = std::sin(t51);
  t80 = std::sin(t52);
  t81 = std::sin(t19);
  t82 = std::sin(t54);
  t83 = std::sin(t55);
  t88 = std::cos(t84);
  t89 = std::cos(t86);
  t90 = in1[1] + t50;
  t91 = t56 * t56;
  t92 = std::sin(t84);
  t94 = std::sin(t86);
  t95 = std::cos(t74);
  t96 = std::cos(t75);
  t97 = std::cos(t76);
  t98 = std::cos(t77);
  t99 = t12 + t55;
  t100 = std::sin(t74);
  t101 = std::sin(t75);
  t102 = std::sin(t76);
  t103 = std::sin(t77);
  t111 = std::cos(t104);
  t112 = std::cos(t105);
  t113 = std::cos(t106);
  t114 = std::cos(t107);
  t19 = in1[5] + t104;
  t125 = std::sin(t104);
  t126 = std::sin(t105);
  t127 = std::sin(t106);
  t128 = std::sin(t107);
  t131 = t15 + t51;
  t84 = t13 + t50;
  t133 = in1[5] + t75;
  t86 = in1[1] + t75;
  t139 = std::cos(t109);
  t140 = t12 + t50;
  t141 = std::sin(t109);
  t142 = std::sin(t110);
  t143 = std::cos(t116);
  t144 = std::cos(t117);
  t145 = std::cos(t118);
  t147 = std::cos(t120);
  t148 = std::cos(t121);
  t149 = std::cos(t122);
  t150 = std::cos(t16);
  t151 = std::cos(t124);
  t152 = t50 - in1[4];
  t153 = t50 - t22;
  t154 = t50 - in1[5];
  t155 = t50 - t23;
  t105 = t51 - in1[5];
  t106 = in1[5] + t116;
  t107 = t52 - in1[5];
  t15 = t54 - in1[4];
  t160 = std::sin(t116);
  t161 = std::sin(t117);
  t162 = std::sin(t118);
  t164 = std::sin(t120);
  t165 = std::sin(t121);
  t166 = std::sin(t122);
  t167 = std::sin(t16);
  t168 = std::sin(t124);
  t172 = t23 + t74;
  t16 = t17 + t74;
  t14 = t13 + t75;
  t181 = std::cos(t137);
  t185 = std::sin(t137);
  t117 = t12 + t74;
  t77 = t12 + t75;
  t120 = -in1[5] + t74;
  t199 = -in1[4] + t75;
  t200 = -t23 + t74;
  t201 = -t22 + t75;
  t223 = t21 + t109;
  t121 = t50 + t74;
  t124 = t50 + t75;
  t52 = t51 + t122;
  t13 = t50 + t118;
  t137 = t75 + t104;
  t51 = t50 + t116;
  t247 = std::cos(t243);
  t54 = -t17 + t50;
  t253 = std::sin(t243);
  t109 = t74 + t75;
  t122 = t74 * 2.0;
  t118 = t75 + t116;
  t115 = std::sin(t99);
  t130 = std::cos(t90);
  t135 = std::sin(t90);
  t136 = std::cos(t99);
  t146 = std::cos(t19);
  t163 = std::sin(t19);
  t169 = std::cos(t131);
  t170 = std::cos(t84);
  t171 = std::cos(t86);
  t175 = std::sin(t131);
  t176 = std::sin(t84);
  t177 = std::sin(t133);
  t178 = std::sin(t86);
  t179 = std::cos(t16);
  t180 = std::cos(t14);
  t182 = std::sin(t172);
  t183 = std::sin(t16);
  t184 = std::sin(t14);
  t186 = std::sin(t22 - t23);
  t187 = std::cos(t140);
  t190 = std::sin(t140);
  t191 = std::cos(t152);
  t192 = std::cos(t153);
  t193 = std::cos(t154);
  t194 = std::cos(t105);
  t195 = std::cos(t106);
  t196 = std::cos(t107);
  t197 = std::cos(t15);
  t202 = std::sin(t152);
  t203 = std::sin(t153);
  t204 = std::sin(t154);
  t205 = std::sin(t155);
  t206 = std::sin(t105);
  t207 = std::sin(t106);
  t208 = std::sin(t107);
  t209 = std::sin(t15);
  t210 = std::cos(t117);
  t211 = std::cos(t77);
  t84 = t12 + t99;
  t214 = std::sin(t117);
  t215 = std::sin(t77);
  t216 = std::cos(t120);
  t217 = std::cos(t199);
  t218 = std::cos(t201);
  t219 = std::sin(t120);
  t220 = std::sin(t199);
  t221 = std::sin(t200);
  t222 = std::sin(t201);
  t16 = -in1[4] + t90;
  t14 = -in1[5] + t90;
  t241 = std::sin(t55 + t76);
  t86 = -in1[5] + t140;
  t19 = -t17 + t152;
  t260 = std::cos(t52);
  t264 = std::sin(t52);
  t77 = -in1[5] + t117;
  t279 = std::cos(t54);
  t281 = std::sin(t54);
  t284 = std::sin(t50 - t110);
  t15 = t74 + t99;
  t105 = -in1[4] + t223;
  t106 = -t22 + t223;
  t116 = -in1[5] + t223;
  t107 = -t17 + t90;
  t52 = t74 + t154;
  t54 = t75 + t152;
  t117 = t75 + t153;
  t104 = -t17 + t140;
  t120 += t74;
  t243 = -t17 + t223;
  t263 = std::sin(-in1[4] + t133);
  t267 = std::sin(-t22 + t133);
  t268 = std::sin(-t23 + t131);
  t280 = std::cos(t19);
  t282 = std::sin(-t17 + t154);
  t283 = std::sin(t19);
  t19 = -t17 + t105;
  ct_idx_158 = std::sin(in1[4] - t23);
  ct_idx_193 = std::cos(t223);
  ct_idx_194 = std::sin(t223);
  ct_idx_195 = std::cos(t16);
  ct_idx_196 = std::cos(t14);
  ct_idx_197 = std::sin(t16);
  ct_idx_198 = std::sin(t14);
  ct_idx_199 = in2[0] * in2[0];
  ct_idx_200 = std::cos(t84);
  ct_idx_202 = std::sin(t84);
  ct_idx_204 = std::cos(t244);
  ct_idx_207 = std::sin(t244);
  ct_idx_208 = std::cos(t121);
  ct_idx_209 = std::cos(t124);
  ct_idx_210 = std::sin(t121);
  ct_idx_211 = std::sin(t124);
  ct_idx_214 = std::cos(t13);
  ct_idx_215 = std::cos(t137);
  ct_idx_218 = std::sin(t13);
  ct_idx_219 = std::sin(t137);
  ct_idx_222 = std::cos(t109);
  ct_idx_224 = std::sin(t109);
  ct_idx_225 = std::cos(t51);
  ct_idx_226 = std::cos(t86);
  ct_idx_227 = std::sin(t51);
  ct_idx_228 = std::sin(t86);
  ct_idx_236 = std::cos(t122);
  t131 = std::sin(t122);
  t154 = std::sin(t75 * 2.0);
  t22 = std::cos(t77);
  t244 = std::cos(t118);
  t133 = std::sin(t77);
  t153 = std::sin(t118);
  t140 = std::cos(t105);
  t50 = std::cos(t106);
  t90 = std::cos(t116);
  t152 = std::sin(t105);
  t55 = std::sin(t106);
  t76 = std::sin(t116);
  t122 = std::sin(-t23 + t223);
  ct_idx_253 = std::cos(t20);
  t118 = std::cos(t107);
  t109 = std::sin(t107);
  t51 = std::cos(t15);
  ct_idx_257 = std::sin(t75 + t99);
  t121 = std::sin(t15);
  t124 = std::cos(t52);
  t13 = std::cos(t54);
  t137 = std::cos(t117);
  ct_idx_262 = std::cos(t21);
  t52 = std::sin(t52);
  t15 = std::sin(t54);
  ct_idx_265 = std::sin(t74 + t155);
  t106 = std::sin(t117);
  t107 = std::cos(t104);
  t105 = std::sin(t104);
  ct_idx_270 = std::sin(t74 + t172);
  t77 = std::cos(t120);
  ct_idx_272 = std::sin(t75 + t199);
  t86 = std::sin(t120);
  ct_idx_274 = std::sin(t75 + t201);
  ct_idx_275 = std::sin(t74 + t200);
  t14 = std::cos(t243);
  t84 = std::cos(t19);
  t16 = std::sin(t243);
  ct_idx_280 = std::sin(-t17 + t116);
  t19 = std::sin(t19);
  ct_idx_282 = std::sin(-t110 + t223);
  ct_idx_283 = t2 * t2;
  ct_idx_284 = t3 * t3;
  ct_idx_285 = t4 * t4;
  ct_idx_286 = t5 * t5;
  ct_idx_287 = t6 * t6;
  ct_idx_290 = std::sin(t20);
  ct_idx_291 = std::sin(t21);
  ct_idx_313 = std::sin(in1[5] + t17);
  d = in2[0] * in2[3];
  d1 = d * t4;
  d2 = in2[0] * in2[4];
  d3 = d2 * t5;
  d4 = in2[0] * in2[5];
  d5 = d4 * t6;
  d6 = d2 * t10;
  d7 = d4 * t11;
  d8 = in2[0] * in2[1];
  d9 = in2[0] * in2[2];
  d10 = in2[1] * in2[2];
  d11 = in2[1] * in2[3];
  d12 = in2[2] * in2[3];
  d13 = in2[4] * in2[5];
  d14 = in2[1] * in2[4];
  d15 = in2[2] * in2[4];
  d16 = in2[3] * in2[4];
  d17 = in2[1] * in2[5];
  d18 = in2[2] * in2[5];
  d19 = in2[3] * in2[5];
  d20 = d2 * t43;
  d21 = d8 * t30;
  d22 = d8 * t40;
  d23 = in2[0] * t18;
  d24 = in2[0] * t56;
  d25 = t2 * t3;
  d26 = d25 * t4;
  d27 = d17 * t2;
  d28 = d18 * t2;
  d29 = d19 * t2;
  d30 = d27 * t3;
  d31 = d27 * t4;
  d32 = d17 * t3;
  d33 = d32 * t4;
  d34 = d28 * t3;
  d35 = d28 * t4;
  d36 = d18 * t3;
  d37 = d36 * t4;
  d38 = d29 * t3;
  d39 = d29 * t4;
  d40 = d19 * t3;
  d41 = d40 * t4;
  d42 = d13 * t2;
  d43 = d14 * t2;
  d44 = d15 * t2;
  d45 = d16 * t2;
  d46 = d9 * t30;
  d47 = d * t30;
  d48 = d4 * t30;
  d49 = d25 * t5;
  d50 = d49 * t6;
  d51 = d50 * t9;
  d52 = t2 * t4;
  d53 = d52 * t5;
  d54 = d53 * t6;
  d55 = d54 * t8;
  d56 = t3 * t4;
  d57 = d56 * t5;
  d58 = d57 * t6;
  d59 = d58 * t7;
  d60 = d26 * t6;
  d61 = d26 * t11;
  d62 = t2 * t6;
  d63 = t3 * t6;
  d64 = t4 * t6;
  d65 = d62 * t8 * t9;
  d66 = d63 * t7 * t9;
  d67 = d64 * t7 * t8;
  d68 = t2 * t8 * t9;
  d69 = d68 * t11;
  d70 = t3 * t7 * t9;
  d71 = d70 * t11;
  d72 = t4 * t7 * t8;
  d73 = d72 * t11;
  d74 = d30 * t6 * t9;
  d75 = d31 * t6 * t8;
  d76 = d33 * t6 * t7;
  d77 = d34 * t6 * t9;
  d78 = d35 * t6 * t8;
  d79 = d37 * t6 * t7;
  d80 = d38 * t6 * t9;
  d81 = d39 * t6 * t8;
  d82 = d41 * t6 * t7;
  d83 = d30 * t9;
  d84 = d83 * t11;
  d31 *= t8;
  d85 = d31 * t11;
  d86 = d33 * t7;
  d87 = d86 * t11;
  d88 = d34 * t9;
  d89 = d88 * t11;
  d35 *= t8;
  d90 = d35 * t11;
  d91 = d37 * t7;
  d92 = d91 * t11;
  d93 = d38 * t9;
  d94 = d93 * t11;
  d39 *= t8;
  d95 = d39 * t11;
  d96 = d41 * t7;
  d97 = d96 * t11;
  d98 = d43 * t3;
  d43 *= t4;
  d99 = d14 * t3 * t4;
  d100 = d17 * t6;
  d101 = d100 * t7 * t8 * t9;
  d102 = d44 * t3;
  d44 *= t4;
  d103 = d15 * t3 * t4;
  d104 = d18 * t6;
  d105 = d104 * t7 * t8 * t9;
  d106 = d45 * t3;
  d45 *= t4;
  d107 = d16 * t3 * t4;
  d108 = d19 * t6;
  d109 = d108 * t7 * t8 * t9;
  d110 = d42 * t3;
  d111 = d13 * t3;
  d112 = d98 * t9;
  d113 = d43 * t8;
  d114 = d99 * t7;
  d115 = d17 * t7 * t8 * t9;
  d116 = d115 * t11;
  d117 = d102 * t9;
  d118 = d44 * t8;
  d119 = d103 * t7;
  d120 = d18 * t7 * t8 * t9;
  d121 = d120 * t11;
  d122 = d106 * t9;
  d123 = d45 * t8;
  d124 = d107 * t7;
  d125 = d19 * t7 * t8 * t9;
  d126 = d125 * t11;
  d127 = d14 * t7 * t8 * t9;
  d128 = d15 * t7 * t8 * t9;
  d129 = d16 * t7 * t8 * t9;
  d130 = d2 * t6;
  d131 = d2 * t11;
  d132 = d48 * ct_idx_253 * ct_idx_262;
  d133 = d21 * ct_idx_253;
  d134 = d21 * ct_idx_262;
  d135 = d8 * ct_idx_253 * ct_idx_262;
  d136 = d46 * ct_idx_253;
  d46 *= ct_idx_262;
  d137 = d9 * ct_idx_253 * ct_idx_262;
  d138 = d47 * ct_idx_253;
  d47 *= ct_idx_262;
  d139 = d * ct_idx_253 * ct_idx_262;
  d140 = d4 * ct_idx_253;
  d141 = d4 * ct_idx_262;
  d142 = d13 * t4;
  d143 = d49 * t9 * t11;
  d144 = d53 * t8 * t11;
  d145 = d57 * t7 * t11;
  d146 = t5 * t6;
  d147 = d146 * t7 * t8 * t9;
  d148 = t5 * t7 * t8 * t9 * t11;
  d149 = d25 * t9 * t10;
  d150 = d52 * t8 * t10;
  d151 = d56 * t7 * t10;
  d152 = t7 * t8 * t9 * t10;
  d153 = d10 * t2;
  d154 = d11 * t2;
  d155 = d12 * t2;
  d30 *= t4;
  d156 = d30 * t5;
  d34 *= t4;
  d157 = d34 * t5;
  d158 = d153 * t3;
  d159 = d158 * t5;
  d160 = d153 * t4;
  d161 = d160 * t5;
  d162 = d10 * t3;
  d163 = d162 * t4;
  d164 = d163 * t5;
  d38 *= t4;
  d165 = d38 * t5;
  d166 = d154 * t3;
  d167 = d166 * t5;
  d168 = d154 * t4;
  d169 = d168 * t5;
  d170 = d11 * t3;
  d171 = d170 * t4;
  d172 = d171 * t5;
  d173 = d155 * t3;
  d174 = d173 * t5;
  d175 = d155 * t4;
  d176 = d175 * t5;
  d177 = d12 * t3;
  d178 = d177 * t4;
  d179 = d178 * t5;
  d180 = d27 * t5;
  d181 = d32 * t5;
  d182 = d17 * t4;
  d183 = d182 * t5;
  d184 = d28 * t5;
  d185 = d36 * t5;
  d186 = d18 * t4;
  d187 = d186 * t5;
  d188 = d10 * t5;
  d189 = d29 * t5;
  d190 = d40 * t5;
  d191 = d19 * t4;
  d192 = d191 * t5;
  d193 = d11 * t5;
  d194 = d12 * t5;
  d195 = d158 * t4;
  d196 = d166 * t4;
  d197 = d173 * t4;
  d198 = d10 * t4;
  d199 = d11 * t4;
  d200 = d12 * t4;
  d201 = d153 * t8 * t9;
  d202 = d162 * t7 * t9;
  d203 = d198 * t7 * t8;
  d204 = d154 * t8 * t9;
  d205 = d170 * t7 * t9;
  d206 = d199 * t7 * t8;
  d207 = d155 * t8 * t9;
  d208 = d177 * t7 * t9;
  d209 = d200 * t7 * t8;
  d210 = d199 * t6;
  d211 = d200 * t6;
  d212 = d183 * t6;
  d213 = d187 * t6;
  d214 = d192 * t6;
  d215 = d193 * t6;
  d216 = d194 * t6;
  d217 = d99 * t6;
  d218 = d103 * t6;
  d219 = d107 * t6;
  d220 = d198 * t6;
  d221 = d188 * t6;
  d222 = d14 * t6;
  d223 = d15 * t6;
  d224 = d16 * t6;
  coriolis_current_tmp_tmp = d3 * t6;
  coriolis_current_tmp = coriolis_current_tmp_tmp * t30;
  b_coriolis_current_tmp_tmp = d3 * t11;
  b_coriolis_current_tmp = b_coriolis_current_tmp_tmp * t30;
  c_coriolis_current_tmp_tmp = d5 * t10;
  c_coriolis_current_tmp = c_coriolis_current_tmp_tmp * t30;
  d_coriolis_current_tmp_tmp = d4 * t10 * t11;
  d_coriolis_current_tmp = d_coriolis_current_tmp_tmp * t30;
  coriolis_current_tmp_tmp_tmp = d8 * t6;
  e_coriolis_current_tmp_tmp = coriolis_current_tmp_tmp_tmp * t10;
  e_coriolis_current_tmp = e_coriolis_current_tmp_tmp * t30;
  b_coriolis_current_tmp_tmp_tmp = d9 * t6;
  f_coriolis_current_tmp_tmp = b_coriolis_current_tmp_tmp_tmp * t10;
  f_coriolis_current_tmp = f_coriolis_current_tmp_tmp * t30;
  c_coriolis_current_tmp_tmp_tmp = d * t6;
  g_coriolis_current_tmp_tmp = c_coriolis_current_tmp_tmp_tmp * t10;
  g_coriolis_current_tmp = g_coriolis_current_tmp_tmp * t30;
  h_coriolis_current_tmp_tmp = d8 * t10 * t11;
  h_coriolis_current_tmp = h_coriolis_current_tmp_tmp * t30;
  i_coriolis_current_tmp_tmp = d9 * t10 * t11;
  i_coriolis_current_tmp = i_coriolis_current_tmp_tmp * t30;
  j_coriolis_current_tmp_tmp = d * t10 * t11;
  j_coriolis_current_tmp = j_coriolis_current_tmp_tmp * t30;
  k_coriolis_current_tmp = d6 * t30;
  k_coriolis_current_tmp_tmp = d8 * t5;
  l_coriolis_current_tmp = k_coriolis_current_tmp_tmp * t30;
  m_coriolis_current_tmp = coriolis_current_tmp_tmp_tmp * t30;
  l_coriolis_current_tmp_tmp = d9 * t5;
  n_coriolis_current_tmp = l_coriolis_current_tmp_tmp * t30;
  o_coriolis_current_tmp = b_coriolis_current_tmp_tmp_tmp * t30;
  m_coriolis_current_tmp_tmp = d * t5;
  p_coriolis_current_tmp = m_coriolis_current_tmp_tmp * t30;
  q_coriolis_current_tmp = c_coriolis_current_tmp_tmp_tmp * t30;
  r_coriolis_current_tmp = d130 * t30;
  n_coriolis_current_tmp_tmp = d4 * t5;
  s_coriolis_current_tmp = n_coriolis_current_tmp_tmp * t30;
  t104 = d8 * t11;
  t_coriolis_current_tmp = t104 * t30;
  t243 = d9 * t11;
  u_coriolis_current_tmp = t243 * t30;
  t116 = d * t11;
  v_coriolis_current_tmp = t116 * t30;
  w_coriolis_current_tmp = d131 * t30;
  x_coriolis_current_tmp = d5 * t30;
  y_coriolis_current_tmp = d7 * t30;
  ab_coriolis_current_tmp = d2 * t30;
    coriolis_current[0] =
      (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
      (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((t2 * t25 *
      0.0811311362192065 - t7 * t25 * 0.01217225609476435) + t25 * t45 * 0.0011471384610227131) - t28 * t45 *
      0.0011471384610227131) + (((t25 * t57 * 0.0024071831784136309 - t28 * t57 * 0.0024071831784136309) - t25 * t68 *
      0.001441653801768) + t25 * t69 * 0.001070188255786817)) + (((t26 * t68 * -0.001441653801768 + t26 * t69 *
      0.001070188255786817) - t27 * t68 * 0.001441653801768) - t25 * t71 * 0.0014001652098252319)) + (((t28 * t69 *
      -0.001070188255786817 + t28 * t71 * 0.0014001652098252319) + t29 * t71 * 0.0014001652098252319) - t25 * t78 *
      0.0040786446926628561)) + (((t25 * t79 * 0.002245709000785428 - t26 * t78 * 0.0040786446926628561) + t26 * t79 *
      0.002245709000785428) - t27 * t78 * 0.0040786446926628561)) + (((t25 * t81 * -0.0016407084290679171 - t28 * t79 *
      0.002245709000785428) + t28 * t81 * 0.0016407084290679171) + t29 * t81 * 0.0016407084290679171)) + (((t25 * t95 *
      6.7726738198090365E-5 + t25 * t96 * 0.00087779373763418168) + t26 * t95 * 6.7726738198090365E-5) - t25 * t97 *
      0.001306241935590179)) + (((t26 * t96 * 0.00087779373763418168 + t27 * t95 * 6.7726738198090365E-5) - t26 * t97 *
      0.001306241935590179) + t27 * t96 * 0.00087779373763418168)) + (((t28 * t95 * -0.0013555913471159759 - t25 * t100 *
      0.001035834994206808) + t28 * t97 * 0.001306241935590179) + t29 * t96 * 0.001371586187968968)) + (((t25 * t101 *
      -0.00074910095606448663 - t26 * t100 * 0.001035834994206808) + t29 * t97 * 0.001306241935590179) - t25 * t102 *
      0.001530649482708048)) + (((t26 * t101 * -0.00074910095606448663 - t27 * t100 * 0.001035834994206808) - t26 * t102
      * 0.001530649482708048) - t27 * t101 * 0.00074910095606448663)) + (((t28 * t100 * 0.00164956436832668 + t28 * t102
      * 0.001530649482708048) - t29 * t101 * 0.001170498809323459) + t29 * t102 * 0.001530649482708048)) + (((t25 * t111
      * 0.0011471384610227131 - t28 * t111 * 0.0011471384610227131) - t25 * t115 * 0.00032084738935769948) - t26 * t115 *
      0.00032084738935769948)) + (((t27 * t115 * -0.00032084738935769948 - t28 * t115 * 0.000428253566706787) - t29 *
      t115 * 0.00084965141996575985) - t25 * t125 * 0.0024071831784136309)) + (((t28 * t125 * 0.0024071831784136309 +
      t68 * t91 * 0.0062999675051760781) + t25 * t136 * 0.000375967787565098) + t26 * t136 * 0.000375967787565098)) +
      (((t27 * t136 * 0.000375967787565098 + t28 * t136 * 0.00050182595006908375) + t29 * t136 * 0.00099561840040387041)
      + t25 * t143 * 0.001070188255786817)) + (((t26 * t143 * 0.001070188255786817 + t78 * t91 * 0.0017191468849424389)
      + t25 * t145 * 0.0014001652098252319) + t25 * t146 * 0.0014001652098252319)) + (((t28 * t143 *
      -0.001070188255786817 - t25 * t148 * 0.0014001652098252319) - t28 * t145 * 0.0014001652098252319) - t28 * t146 *
      0.0014001652098252319)) + (((t29 * t145 * -0.0014001652098252319 - t29 * t146 * 0.0014001652098252319) + t28 *
      t148 * 0.0014001652098252319) + t29 * t148 * 0.0014001652098252319)) + (((t25 * t160 * -0.002245709000785428 - t26
      * t160 * 0.002245709000785428) - t25 * t162 * 0.0016407084290679171) + t25 * t163 * 0.0016407084290679171)) +
      (((t28 * t160 * 0.002245709000785428 - t25 * t165 * 0.0016407084290679171) + t28 * t162 * 0.0016407084290679171) -
      t28 * t163 * 0.0016407084290679171)) + (((t29 * t162 * 0.0016407084290679171 - t29 * t163 * 0.0016407084290679171)
      + t28 * t165 * 0.0016407084290679171) - t25 * t169 * 0.003837110775246145)) + (((t29 * t165 *
      0.0016407084290679171 - t26 * t169 * 0.003837110775246145) - t27 * t169 * 0.003837110775246145) + t25 * t175 *
      0.000323031894834975)) + (((t26 * t175 * 0.000323031894834975 + t27 * t175 * 0.000323031894834975) + t25 * t179 *
      0.00024689622516739339) + t26 * t179 * 0.00024689622516739339)) + (((t27 * t179 * 0.00024689622516739339 - t25 *
      t182 * 0.0011395919218959709) - t25 * t183 * 0.00021069892662948649) - t26 * t182 * 0.0011395919218959709)) +
      (((t26 * t183 * -0.00021069892662948649 - t27 * t182 * 0.0011395919218959709) - t27 * t183 *
      0.00021069892662948649) + t28 * t182 * 0.0011395919218959709)) + (((t25 * t191 * -0.0013555913471159759 - t25 *
      t192 * 0.003837110775246145) - t26 * t191 * 0.0013555913471159759) - t25 * t193 * 0.00087779373763418168)) +
      (((t26 * t192 * -0.003837110775246145 - t27 * t191 * 0.0013555913471159759) + t25 * t194 * 0.001306241935590179) -
      t26 * t193 * 0.00087779373763418168)) + (((t27 * t192 * -0.003837110775246145 + t28 * t191 * 6.7726738198090365E-5)
      + t25 * t195 * 0.001306241935590179) + t26 * t194 * 0.001306241935590179)) + (((t27 * t193 *
      -0.00087779373763418168 + t26 * t195 * 0.001306241935590179) - t28 * t194 * 0.001306241935590179) - t29 * t193 *
      0.00038400128729939491)) + (((t28 * t195 * -0.001306241935590179 - t29 * t194 * 0.001306241935590179) - t29 * t195
      * 0.001306241935590179) - t25 * t202 * 0.00164956436832668)) + (((t25 * t203 * -0.000323031894834975 - t26 * t202 *
      0.00164956436832668) - t25 * t204 * 0.00074910095606448663) - t26 * t203 * 0.000323031894834975)) + (((t27 * t202 *
      -0.00164956436832668 - t26 * t204 * 0.00074910095606448663) - t27 * t203 * 0.000323031894834975) + t28 * t202 *
      0.001035834994206808)) + (((t25 * t206 * -0.001530649482708048 - t27 * t204 * 0.00074910095606448663) + t25 * t207
      * 0.001530649482708048) - t26 * t206 * 0.001530649482708048)) + (((t26 * t207 * 0.001530649482708048 - t29 * t204 *
      0.0003277031028055136) + t28 * t206 * 0.001530649482708048) - t28 * t207 * 0.001530649482708048)) + (((t29 * t206 *
      0.001530649482708048 - t29 * t207 * 0.001530649482708048) - t25 * t216 * 0.0001178246627696888) + t25 * t217 *
      0.00099561840040387041)) + (((t26 * t216 * -0.0001178246627696888 + t25 * t218 * 0.00024689622516739339) + t26 *
      t217 * 0.00099561840040387041) - t27 * t216 * 0.0001178246627696888)) + (((t25 * t219 * -0.0001005504639012734 +
      t26 * t218 * 0.00024689622516739339) + t27 * t217 * 0.00099561840040387041) + t28 * t216 * 0.00099561840040387041))
      + (((t25 * t220 * -0.00084965141996575985 - t26 * t219 * 0.0001005504639012734) + t27 * t218 *
      0.00024689622516739339) - t28 * t217 * 0.0001178246627696888)) + (((t29 * t216 * 0.00050182595006908375 + t25 *
      t221 * 0.0011395919218959709) - t26 * t220 * 0.00084965141996575985) - t27 * t219 * 0.0001005504639012734)) +
      (((t29 * t217 * 0.000375967787565098 - t25 * t222 * 0.00021069892662948649) + t26 * t221 * 0.0011395919218959709)
      - t27 * t220 * 0.00084965141996575985)) + (((t28 * t219 * 0.00084965141996575985 - t26 * t222 *
      0.00021069892662948649) + t27 * t221 * 0.0011395919218959709) + t28 * t220 * 0.0001005504639012734)) + (((t29 *
      t219 * 0.000428253566706787 - t27 * t222 * 0.00021069892662948649) - t28 * t221 * 0.0011395919218959709) - t29 *
      t220 * 0.00032084738935769948)) + (((t25 * t241 * -0.00056979596094798557 - t26 * t241 * 0.00056979596094798557) -
      t27 * t241 * 0.00056979596094798557) - t25 * t247 * 0.001306241935590179)) + (((t26 * t247 * -0.001306241935590179
      + t28 * t247 * 0.001306241935590179) + t29 * t247 * 0.001306241935590179) + t25 * t253 * 0.001530649482708048)) +
      (((t26 * t253 * 0.001530649482708048 - t28 * t253 * 0.001530649482708048) - t29 * t253 * 0.001530649482708048) +
      t25 * t260 * 0.00024689622516739339)) + (((t26 * t260 * 0.00024689622516739339 + t27 * t260 *
      0.00024689622516739339) + t25 * t263 * 0.0011395919218959709) + t25 * t264 * 0.00021069892662948649)) + (((t26 *
      t263 * 0.0011395919218959709 + t26 * t264 * 0.00021069892662948649) + t27 * t263 * 0.0011395919218959709) + t27 *
      t264 * 0.00021069892662948649)) + (((t28 * t263 * -0.0011395919218959709 + t25 * t267 * 0.00056979596094798557) -
      t25 * t268 * 0.00056979596094798557) + t26 * t267 * 0.00056979596094798557)) + (((t26 * t268 *
      -0.00056979596094798557 + t27 * t267 * 0.00056979596094798557) - t27 * t268 * 0.00056979596094798557) + t25 * t279
      * 0.00050182595006908375)) + (((t25 * t280 * 0.00024689622516739339 + t26 * t279 * 0.00050182595006908375) + t25 *
      t281 * 0.000428253566706787) + t26 * t280 * 0.00024689622516739339)) + (((t27 * t279 * 0.00050182595006908375 -
      t25 * t282 * 0.0011395919218959709) + t26 * t281 * 0.000428253566706787) + t27 * t280 * 0.00024689622516739339)) +
      (((t28 * t279 * 0.000375967787565098 + t25 * t283 * 0.00021069892662948649) - t26 * t282 * 0.0011395919218959709)
      + t27 * t281 * 0.000428253566706787)) + (((t29 * t279 * -0.0001178246627696888 + t25 * t284 *
      0.00056979596094798557) + t26 * t283 * 0.00021069892662948649) - t27 * t282 * 0.0011395919218959709)) + (((t28 *
      t281 * 0.00032084738935769948 + t26 * t284 * 0.00056979596094798557) + t27 * t283 * 0.00021069892662948649) + t28 *
      t282 * 0.0011395919218959709)) + ((t29 * t281 * -0.0001005504639012734 + t27 * t284 * 0.00056979596094798557) +
      in2[0] * ((((in2[2] * t3 * 6127.0 + in2[1] * t88 * 12254.0) + in2[2] * t88 * 6127.0) + in2[1] * t139 * 11432.0) +
      in2[2] * t139 * 11432.0) * 7.6108859250686316E-7)) + ((in2[0] * ((((in2[2] * t8 * 6127.0 + in2[1] * t92 * 12254.0)
      + in2[2] * t92 * 6127.0) + in2[1] * t141 * 11432.0) + in2[2] * t141 * 11432.0) * -2.3817692682078551E-5 + t87 *
      std::cos(t12) * 0.032407697913222767) + t87 * std::sin(t12) * 0.0015106195401031451)) + (((d1 *
      -0.014224242259463629 + d3 * 0.00257572921783577) + d5 * 0.001239301225677545) + d * t9 * 0.00502775663874673)) +
      (((d6 * -0.001227458748239743 - d7 * 0.001057608061216121) + d21 * 0.0010813564402818751) + d2 * t33 *
      0.0076742215504922908)) + (((d4 * t34 * -0.0018507243915179719 - d22 * 0.3106640765298459) - d20 *
      0.00064606378966995) - d9 * t46 * 0.01524701405243766)) + (((d * t46 * -0.01524701405243766 - d4 * t44 *
      0.0022791838437919432) + d * t47 * 0.001070188255786817) - d * t48 * 0.0026124838711803571)) + (((d2 * t47 *
      0.001070188255786817 - d2 * t49 * 0.0017555874752683629) - d4 * t48 * 0.0026124838711803571) - d4 * t49 *
      0.0017555874752683629)) + (((d9 * t58 * 0.0053892695811058808 + d * t58 * 0.0053892695811058808) + d * t59 *
      0.002245709000785428) - d * t60 * 0.0030612989654160969)) + (((d2 * t59 * 0.002245709000785428 + d2 * t61 *
      0.001498201912128973) - d4 * t60 * 0.0030612989654160969) + d4 * t61 * 0.001498201912128973)) + (((d10 * t68 *
      -0.002883307603536001 + d9 * t70 * 0.0011471384610227131) + d10 * t69 * 0.002140376511573634) - d11 * t68 *
      0.002883307603536001)) + (((d * t70 * 0.0011471384610227131 - d12 * t68 * 0.002883307603536001) - d9 * t72 *
      0.002800330419650463) + d2 * t70 * 0.0011471384610227131)) + (((d * t72 * -0.002800330419650463 - d * t73 *
      0.001306241935590179) - d2 * t73 * 0.001306241935590179) - d4 * t72 * 0.002800330419650463)) + (((d4 * t73 *
      -0.001306241935590179 + d13 * t71 * 0.002800330419650463) - d10 * t78 * 0.0081572893853257122) + d9 * t80 *
      0.0024071831784136309)) + (((d10 * t79 * 0.0044914180015708551 - d11 * t78 * 0.0081572893853257122) + d * t80 *
      0.0024071831784136309) + d14 * t78 * 0.006574306978599744)) + (((d12 * t78 * -0.0081572893853257122 - d9 * t82 *
      0.0032814168581358342) + d2 * t80 * 0.0024071831784136309) + d15 * t78 * 0.006574306978599744)) + (((d * t82 *
      -0.0032814168581358342 + d16 * t78 * 0.006574306978599744) - d * t83 * 0.001530649482708048) - d2 * t83 *
      0.001530649482708048)) + (((d4 * t82 * -0.0032814168581358342 - d4 * t83 * 0.001530649482708048) + d13 * t81 *
      0.0032814168581358342) - d2 * t89 * 0.00049379245033478677)) + (((d4 * t89 * -0.00024689622516739339 + d2 * t94 *
      0.00042139785325897292) + d10 * t95 * 0.0001354534763961807) + d4 * t94 * 0.00021069892662948649)) + (((d10 * t96 *
      0.0017555874752683629 + d11 * t95 * 0.0001354534763961807) - d9 * t98 * 0.0014001652098252319) - d10 * t97 *
      0.0026124838711803571)) + (((d11 * t96 * 0.0017555874752683629 - d14 * t95 * 0.001287864608917885) + d12 * t95 *
      0.0001354534763961807) - d * t98 * 0.0014001652098252319)) + (((d12 * t96 * 0.0017555874752683629 - d15 * t95 *
      0.001287864608917885) - d2 * t98 * 0.0014001652098252319) + d17 * t96 * 0.00224937992560315)) + (((d16 * t95 *
      -0.001287864608917885 - d4 * t98 * 0.0014001652098252319) - d10 * t100 * 0.0020716699884136161) + d18 * t96 *
      0.00224937992560315)) + (((d10 * t101 * -0.001498201912128973 - d11 * t100 * 0.0020716699884136161) + d19 * t96 *
      0.00224937992560315) - d9 * t103 * 0.0016407084290679171)) + (((d10 * t102 * -0.0030612989654160969 - d11 * t101 *
      0.001498201912128973) + d14 * t100 * 0.00061372937411987162) - d12 * t100 * 0.0020716699884136161)) + (((d * t103 *
      -0.0016407084290679171 + d17 * t100 * 0.00154800380240164) - d12 * t101 * 0.001498201912128973) + d15 * t100 *
      0.00061372937411987162)) + (((d13 * t97 * 0.0026124838711803571 - d2 * t103 * 0.0016407084290679171) - d17 * t101 *
      0.0019195997653879461) + d18 * t100 * 0.00154800380240164)) + (((d16 * t100 * 0.00061372937411987162 - d4 * t103 *
      0.0016407084290679171) - d18 * t101 * 0.0019195997653879461) + d19 * t100 * 0.00154800380240164)) + (((d19 * t101 *
      -0.0019195997653879461 + d13 * t100 * 0.00154800380240164) + d13 * t102 * 0.0030612989654160969) - d * t112 *
      0.001070188255786817)) + (((d * t113 * -0.0026124838711803571 + d2 * t112 * 0.001070188255786817) - d2 * t114 *
      0.0017555874752683629) + d4 * t113 * 0.0026124838711803571)) + (((d10 * t115 * -0.00064169477871539907 + d4 * t114
      * 0.0017555874752683629) - d11 * t115 * 0.00064169477871539907) - d14 * t115 * 0.00074910095606448663)) + (((d12 *
      t115 * -0.00064169477871539907 - d17 * t115 * 0.001170498809323459) - d15 * t115 * 0.00074910095606448663) - d18 *
      t115 * 0.001170498809323459)) + (((d16 * t115 * -0.00074910095606448663 - d19 * t115 * 0.001170498809323459) - d13
      * t115 * 0.0012779049866725469) + d * t126 * 0.002245709000785428)) + (((d * t127 * 0.0030612989654160969 - d2 *
      t126 * 0.002245709000785428) - d8 * t130 * 0.03049402810487532) - d9 * t130 * 0.01524701405243766)) + (((d2 * t128
      * -0.001498201912128973 - d4 * t127 * 0.0030612989654160969) - d * t130 * 0.01524701405243766) + d4 * t128 *
      0.001498201912128973)) + (((d8 * t135 * 0.01077853916221176 + d9 * t135 * 0.0053892695811058808) + d * t135 *
      0.0053892695811058808) + d10 * t136 * 0.00075193557513019587)) + (((d11 * t136 * 0.00075193557513019587 + d14 *
      t136 * 0.00087779373763418168) + d12 * t136 * 0.00075193557513019587) + d17 * t136 * 0.001371586187968968)) +
      (((d15 * t136 * 0.00087779373763418168 + d18 * t136 * 0.001371586187968968) + d16 * t136 * 0.00087779373763418168)
      + d19 * t136 * 0.001371586187968968)) + (((d13 * t136 * 0.0014974443504729539 - d9 * t144 * 0.0011471384610227131)
      + d2 * t142 * 0.0011395919218959709) + d10 * t143 * 0.002140376511573634)) + (((d * t144 * -0.0011471384610227131
      + d4 * t142 * 0.0011395919218959709) + d2 * t144 * 0.0011471384610227131) - d9 * t147 * 0.002800330419650463)) +
      (((d * t147 * -0.002800330419650463 + d * t149 * 0.001306241935590179) + d4 * t147 * 0.002800330419650463) - d *
      t150 * 0.001306241935590179)) + (((d2 * t149 * 0.001306241935590179 + d * t151 * 0.001306241935590179) + d2 * t150
      * 0.001306241935590179) - d4 * t149 * 0.001306241935590179)) + (((d13 * t145 * 0.002800330419650463 - d2 * t151 *
      0.001306241935590179) - d4 * t150 * 0.001306241935590179) + d13 * t146 * 0.002800330419650463)) + (((d4 * t151 *
      -0.001306241935590179 + d13 * t148 * 0.002800330419650463) + d9 * t161 * 0.0024071831784136309) - d10 * t160 *
      0.0044914180015708551)) + (((d * t161 * 0.0024071831784136309 - d2 * t161 * 0.0024071831784136309) + d9 * t164 *
      0.0032814168581358342) + d * t164 * 0.0032814168581358342)) + (((d * t166 * -0.001530649482708048 - d4 * t164 *
      0.0032814168581358342) - d * t167 * 0.001530649482708048) - d2 * t166 * 0.001530649482708048)) + (((d8 * t170 *
      0.0022942769220454262 + d * t168 * 0.001530649482708048) + d2 * t167 * 0.001530649482708048) + d4 * t166 *
      0.001530649482708048)) + (((d13 * t162 * -0.0032814168581358342 - d8 * t171 * 0.005600660839300926) + d9 * t170 *
      0.0011471384610227131) - d2 * t168 * 0.001530649482708048)) + (((d4 * t167 * -0.001530649482708048 - d10 * t169 *
      0.0076742215504922908) + d13 * t163 * 0.0032814168581358342) - d9 * t171 * 0.002800330419650463)) + (((d * t170 *
      0.0011471384610227131 - d4 * t168 * 0.001530649482708048) - d11 * t169 * 0.0076742215504922908) - d * t171 *
      0.002800330419650463)) + (((d2 * t170 * 0.0011471384610227131 - d14 * t169 * 0.0076742215504922908) - d12 * t169 *
      0.0076742215504922908) + d13 * t165 * 0.0032814168581358342)) + (((d15 * t169 * -0.0076742215504922908 - d4 * t171
      * 0.002800330419650463) - d16 * t169 * 0.0076742215504922908) + d8 * t176 * 0.0048143663568272618)) + (((d9 * t176
      * 0.0024071831784136309 + d10 * t175 * 0.00064606378966995) - d8 * t178 * 0.0065628337162716667) + d * t176 *
      0.0024071831784136309)) + (((d11 * t175 * 0.00064606378966995 - d9 * t178 * 0.0032814168581358342) + d2 * t176 *
      0.0024071831784136309) + d14 * t175 * 0.00064606378966995)) + (((d12 * t175 * 0.00064606378966995 - d8 * t180 *
      0.002800330419650463) - d * t178 * 0.0032814168581358342) + d15 * t175 * 0.00064606378966995)) + (((d9 * t180 *
      -0.0014001652098252319 + d10 * t179 * 0.00049379245033478677) + d14 * t177 * 0.0022791838437919432) + d16 * t175 *
      0.00064606378966995)) + (((d * t180 * -0.0014001652098252319 - d4 * t178 * 0.0032814168581358342) + d11 * t179 *
      0.00049379245033478677) + d15 * t177 * 0.0022791838437919432)) + (((d2 * t180 * -0.0014001652098252319 + d14 *
      t179 * 0.00049379245033478677) + d12 * t179 * 0.00049379245033478677) + d16 * t177 * 0.0022791838437919432)) +
      (((d8 * t184 * -0.0032814168581358342 - d2 * t181 * 0.00049379245033478677) - d4 * t180 * 0.0014001652098252319) -
      d10 * t182 * 0.0022791838437919432)) + (((d17 * t179 * 0.00024689622516739339 + d15 * t179 *
      0.00049379245033478677) - d9 * t184 * 0.0016407084290679171) + d4 * t181 * 0.00024689622516739339)) + (((d10 *
      t183 * -0.00042139785325897292 - d11 * t182 * 0.0022791838437919432) + d18 * t179 * 0.00024689622516739339) + d16 *
      t179 * 0.00049379245033478677)) + (((d13 * t177 * 0.0045583676875838846 - d * t184 * 0.0016407084290679171) - d11 *
      t183 * 0.00042139785325897292) - d12 * t182 * 0.0022791838437919432)) + (((d19 * t179 * 0.00024689622516739339 -
      d8 * t187 * 0.028448484518927258) - d2 * t184 * 0.0016407084290679171) - d14 * t183 * 0.00042139785325897292)) +
      (((d17 * t182 * -0.0022791838437919432 - d12 * t183 * 0.00042139785325897292) - d9 * t187 * 0.028448484518927258)
      - d2 * t185 * 0.00042139785325897292)) + (((d4 * t184 * -0.0016407084290679171 - d17 * t183 *
      0.00021069892662948649) - d15 * t183 * 0.00042139785325897292) - d18 * t182 * 0.0022791838437919432)) + (((d *
      t187 * -0.014224242259463629 + d2 * t186 * 0.0011395919218959709) + d4 * t185 * 0.00021069892662948649) - d18 *
      t183 * 0.00021069892662948649)) + (((d16 * t183 * -0.00042139785325897292 - d19 * t182 * 0.0022791838437919432) +
      d8 * t190 * 0.010055513277493461) - d4 * t186 * 0.0011395919218959709)) + (((d19 * t183 * -0.00021069892662948649
      + d13 * t182 * 0.0022791838437919432) + d9 * t190 * 0.010055513277493461) + d * t190 * 0.00502775663874673)) +
      (((d10 * t191 * -0.0027111826942319509 - d10 * t192 * 0.0076742215504922908) - d11 * t191 * 0.0027111826942319509)
      - d10 * t193 * 0.0017555874752683629)) + (((d11 * t192 * -0.0076742215504922908 + d14 * t191 *
      0.001287864608917885) - d12 * t191 * 0.0027111826942319509) + d10 * t194 * 0.0026124838711803571)) + (((d11 * t193
      * -0.0017555874752683629 + d14 * t192 * 0.0076742215504922908) - d12 * t192 * 0.0076742215504922908) + d15 * t191 *
      0.001287864608917885)) + (((d9 * t196 * 0.0014001652098252319 + d10 * t195 * 0.0026124838711803571) - d12 * t193 *
      0.0017555874752683629) + d15 * t192 * 0.0076742215504922908)) + (((d16 * t191 * 0.001287864608917885 - d9 * t197 *
      0.0014001652098252319) + d * t196 * 0.0014001652098252319) + d17 * t193 * 0.0012617950249335769)) + (((d16 * t192 *
      0.0076742215504922908 - d * t197 * 0.0014001652098252319) + d2 * t196 * 0.0014001652098252319) + d18 * t193 *
      0.0012617950249335769)) + (((d2 * t197 * 0.0014001652098252319 - d4 * t196 * 0.0014001652098252319) + d19 * t193 *
      0.0012617950249335769) - d4 * t197 * 0.0014001652098252319)) + (((d13 * t194 * 0.0026124838711803571 + d13 * t195 *
      0.0026124838711803571) - d10 * t202 * 0.0032991287366533591) - d10 * t203 * 0.00064606378966995)) + (((d11 * t202 *
      -0.0032991287366533591 - d10 * t204 * 0.001498201912128973) - d11 * t203 * 0.00064606378966995) + d14 * t202 *
      0.00061372937411987162)) + (((d12 * t202 * -0.0032991287366533591 - d11 * t204 * 0.001498201912128973) + d14 *
      t203 * 0.00064606378966995) - d17 * t202 * 0.00154800380240164)) + (((d12 * t203 * -0.00064606378966995 + d15 *
      t202 * 0.00061372937411987162) - d10 * t206 * 0.0030612989654160969) - d12 * t204 * 0.001498201912128973)) +
      (((d15 * t203 * 0.00064606378966995 - d18 * t202 * 0.00154800380240164) + d16 * t202 * 0.00061372937411987162) -
      d9 * t208 * 0.0016407084290679171)) + (((d10 * t207 * 0.0030612989654160969 + d14 * t205 * 0.0022791838437919432)
      + d17 * t204 * 0.00107680405887) + d16 * t203 * 0.00064606378966995)) + (((d19 * t202 * -0.00154800380240164 + d8 *
      t210 * 0.002140376511573634) - d9 * t209 * 0.0016407084290679171) - d * t208 * 0.0016407084290679171)) + (((d15 *
      t205 * 0.0022791838437919432 + d18 * t204 * 0.00107680405887) + d13 * t202 * 0.00154800380240164) - d8 * t211 *
      0.0052249677423607142)) + (((d9 * t210 * 0.002140376511573634 - d * t209 * 0.0016407084290679171) - d2 * t208 *
      0.0016407084290679171) + d16 * t205 * 0.0022791838437919432)) + (((d19 * t204 * 0.00107680405887 - d9 * t211 *
      0.0052249677423607142) + d * t210 * 0.001070188255786817) + d2 * t209 * 0.0016407084290679171)) + (((d4 * t208 *
      0.0016407084290679171 - d * t211 * 0.0026124838711803571) + d2 * t210 * 0.001070188255786817) - d4 * t209 *
      0.0016407084290679171)) + (((d13 * t205 * -0.0045583676875838846 + d8 * t214 * 0.0044914180015708551) - d13 * t206
      * 0.0030612989654160969) - d8 * t215 * 0.006122597930832193)) + (((d9 * t214 * 0.0044914180015708551 - d4 * t211 *
      0.0026124838711803571) + d13 * t207 * 0.0030612989654160969) - d9 * t215 * 0.006122597930832193)) + (((d * t214 *
      0.002245709000785428 - d * t215 * 0.0030612989654160969) + d2 * t214 * 0.002245709000785428) - d10 * t216 *
      0.00023564932553937759)) + (((d4 * t215 * -0.0030612989654160969 + d10 * t217 * 0.0019912368008077408) - d11 *
      t216 * 0.00023564932553937759) + d10 * t218 * 0.00049379245033478677)) + (((d11 * t217 * 0.0019912368008077408 +
      d14 * t216 * 0.00087779373763418168) - d12 * t216 * 0.00023564932553937759) - d10 * t219 * 0.00020110092780254669))
      + (((d11 * t218 * 0.00049379245033478677 - d14 * t217 * 0.00087779373763418168) - d17 * t216 *
      0.00038400128729939491) + d12 * t217 * 0.0019912368008077408)) + (((d15 * t216 * 0.00087779373763418168 - d10 *
      t220 * 0.00169930283993152) - d11 * t219 * 0.00020110092780254669) - d14 * t218 * 0.00049379245033478677)) +
      (((d17 * t217 * 0.001371586187968968 + d12 * t218 * 0.00049379245033478677) - d15 * t217 * 0.00087779373763418168)
      - d18 * t216 * 0.00038400128729939491)) + (((d16 * t216 * 0.00087779373763418168 + d10 * t221 *
      0.0022791838437919432) - d11 * t220 * 0.00169930283993152) + d14 * t219 * 0.00074910095606448663)) + (((d17 * t218
      * 0.00024689622516739339 - d12 * t219 * 0.00020110092780254669) - d15 * t218 * 0.00049379245033478677) + d18 *
      t217 * 0.001371586187968968)) + (((d16 * t217 * -0.00087779373763418168 - d19 * t216 * 0.00038400128729939491) -
      d10 * t222 * 0.00042139785325897292) + d11 * t221 * 0.0022791838437919432)) + (((d14 * t220 *
      0.00074910095606448663 - d17 * t219 * 0.0003277031028055136) - d12 * t220 * 0.00169930283993152) + d15 * t219 *
      0.00074910095606448663)) + (((d18 * t218 * 0.00024689622516739339 - d16 * t218 * 0.00049379245033478677) + d19 *
      t217 * 0.001371586187968968) - d13 * t216 * 0.0014974443504729539)) + (((d11 * t222 * -0.00042139785325897292 -
      d17 * t220 * 0.001170498809323459) + d12 * t221 * 0.0022791838437919432) + d15 * t220 * 0.00074910095606448663)) +
      (((d18 * t219 * -0.0003277031028055136 + d16 * t219 * 0.00074910095606448663) + d19 * t218 *
      0.00024689622516739339) - d13 * t217 * 0.0002581431247954091)) + (((d14 * t222 * 0.00042139785325897292 - d17 *
      t221 * 0.0022791838437919432) - d12 * t222 * 0.00042139785325897292) - d18 * t220 * 0.001170498809323459)) +
      (((d16 * t220 * 0.00074910095606448663 - d19 * t219 * 0.0003277031028055136) - d17 * t222 * 0.00021069892662948649)
      + d15 * t222 * 0.00042139785325897292)) + (((d18 * t221 * -0.0022791838437919432 - d19 * t220 *
      0.001170498809323459) - d13 * t219 * 0.0012779049866725469) - d18 * t222 * 0.00021069892662948649)) + (((d16 *
      t222 * 0.00042139785325897292 - d19 * t221 * 0.0022791838437919432) + d13 * t220 * 0.00022029692545642621) + d8 *
      ct_idx_194 * 0.00092322209745153774)) + (((d19 * t222 * -0.00021069892662948649 + d13 * t221 *
      0.0022791838437919432) - d8 * ct_idx_195 * 0.0022942769220454262) + d9 * ct_idx_194 * 0.00092322209745153774)) +
      (((d8 * ct_idx_196 * -0.005600660839300926 - d9 * ct_idx_195 * 0.0011471384610227131) + d * ct_idx_194 *
      0.00092322209745153774) - d9 * ct_idx_196 * 0.002800330419650463)) + (((d * ct_idx_195 * -0.0011471384610227131 -
      d * ct_idx_196 * 0.002800330419650463) + d2 * ct_idx_195 * 0.0011471384610227131) + d4 * ct_idx_196 *
      0.002800330419650463)) + (((d8 * ct_idx_197 * 0.0048143663568272618 + d8 * ct_idx_198 * 0.0065628337162716667) +
      d9 * ct_idx_197 * 0.0024071831784136309) - d8 * ct_idx_200 * 0.0026124838711803571)) + (((d9 * ct_idx_198 *
      0.0032814168581358342 + d * ct_idx_197 * 0.0024071831784136309) - d9 * ct_idx_200 * 0.0026124838711803571) + d *
      ct_idx_198 * 0.0032814168581358342)) + (((d2 * ct_idx_197 * -0.0024071831784136309 - d8 * ct_idx_202 *
      0.0030612989654160969) - d * ct_idx_200 * 0.001306241935590179) - d9 * ct_idx_202 * 0.0030612989654160969)) +
      (((d2 * ct_idx_200 * -0.001306241935590179 - d4 * ct_idx_198 * 0.0032814168581358342) - d10 * t241 *
      0.0011395919218959709) - d * ct_idx_202 * 0.001530649482708048)) + (((d4 * ct_idx_200 * -0.001306241935590179 -
      d11 * t241 * 0.0011395919218959709) - d2 * ct_idx_202 * 0.001530649482708048) - d14 * t241 * 0.0011395919218959709))
      + (((d12 * t241 * -0.0011395919218959709 - d4 * ct_idx_202 * 0.001530649482708048) - d17 * t241 *
      0.0011395919218959709) - d15 * t241 * 0.0011395919218959709)) + (((d18 * t241 * -0.0011395919218959709 - d16 *
      t241 * 0.0011395919218959709) - d19 * t241 * 0.0011395919218959709) + d9 * ct_idx_204 * 0.0014001652098252319)) +
      (((d10 * t247 * -0.0026124838711803571 + d * ct_idx_204 * 0.0014001652098252319) - d2 * ct_idx_204 *
      0.0014001652098252319) - d4 * ct_idx_204 * 0.0014001652098252319)) + (((d8 * ct_idx_208 * 0.0014233180853140659 -
      d9 * ct_idx_207 * 0.0016407084290679171) + d10 * t253 * 0.0030612989654160969) + d13 * t247 *
      0.0026124838711803571)) + (((d8 * ct_idx_209 * -0.001239301225677545 + d9 * ct_idx_208 * 0.0014233180853140659) -
      d * ct_idx_207 * 0.0016407084290679171) - d9 * ct_idx_209 * 0.001239301225677545)) + (((d * ct_idx_208 *
      0.0014233180853140659 + d2 * ct_idx_207 * 0.0016407084290679171) - d8 * ct_idx_210 * 0.0026853993625334878) - d *
      ct_idx_209 * 0.001239301225677545)) + (((d2 * ct_idx_208 * 0.000711659042657033 + d4 * ct_idx_207 *
      0.0016407084290679171) + d8 * ct_idx_211 * 0.001057608061216121) - d9 * ct_idx_210 * 0.0026853993625334878)) +
      (((d9 * ct_idx_211 * 0.001057608061216121 - d * ct_idx_210 * 0.0026853993625334878) - d4 * ct_idx_209 *
      0.00061965061283877248) + d8 * ct_idx_214 * 0.002800330419650463)) + (((d * ct_idx_211 * 0.001057608061216121 - d2
      * ct_idx_210 * 0.0013426996812667439) - d13 * t253 * 0.0030612989654160969) - d8 * ct_idx_215 *
      0.002800330419650463)) + (((d9 * ct_idx_214 * 0.0014001652098252319 + d10 * t260 * 0.00049379245033478677) - d9 *
      ct_idx_215 * 0.0014001652098252319) + d * ct_idx_214 * 0.0014001652098252319)) + (((d4 * ct_idx_211 *
      0.00052880403060806037 + d11 * t260 * 0.00049379245033478677) - d * ct_idx_215 * 0.0014001652098252319) + d2 *
      ct_idx_214 * 0.0014001652098252319)) + (((d14 * t260 * 0.00049379245033478677 + d12 * t260 *
      0.00049379245033478677) - d8 * ct_idx_218 * 0.0032814168581358342) + d2 * ct_idx_215 * 0.0014001652098252319)) +
      (((d4 * ct_idx_214 * -0.0014001652098252319 + d10 * t263 * 0.0022791838437919432) - d17 * t260 *
      0.00024689622516739339) + d15 * t260 * 0.00049379245033478677)) + (((d8 * ct_idx_219 * -0.0032814168581358342 - d9
      * ct_idx_218 * 0.0016407084290679171) - d4 * ct_idx_215 * 0.0014001652098252319) + d10 * t264 *
      0.00042139785325897292)) + (((d11 * t263 * 0.0022791838437919432 - d18 * t260 * 0.00024689622516739339) + d16 *
      t260 * 0.00049379245033478677) - d9 * ct_idx_219 * 0.0016407084290679171)) + (((d * ct_idx_218 *
      -0.0016407084290679171 + d11 * t264 * 0.00042139785325897292) + d12 * t263 * 0.0022791838437919432) - d19 * t260 *
      0.00024689622516739339)) + (((d * ct_idx_219 * -0.0016407084290679171 - d2 * ct_idx_218 * 0.0016407084290679171) +
      d14 * t264 * 0.00042139785325897292) + d17 * t263 * 0.0022791838437919432)) + (((d12 * t264 *
      0.00042139785325897292 - d8 * ct_idx_222 * 0.00012585816250398581) + d2 * ct_idx_219 * 0.0016407084290679171) + d4
      * ct_idx_218 * 0.0016407084290679171)) + (((d10 * t267 * 0.0011395919218959709 - d17 * t264 *
      0.00021069892662948649) + d15 * t264 * 0.00042139785325897292) + d18 * t263 * 0.0022791838437919432)) + (((d8 *
      ct_idx_224 * 0.0001074061773490875 - d9 * ct_idx_222 * 0.00012585816250398581) - d4 * ct_idx_219 *
      0.0016407084290679171) - d10 * t268 * 0.0011395919218959709)) + (((d11 * t267 * 0.0011395919218959709 - d18 * t264
      * 0.00021069892662948649) + d16 * t264 * 0.00042139785325897292) + d19 * t263 * 0.0022791838437919432)) + (((d9 *
      ct_idx_224 * 0.0001074061773490875 - d * ct_idx_222 * 0.00012585816250398581) - d11 * t268 * 0.0011395919218959709)
      - d14 * t267 * 0.0011395919218959709)) + (((d12 * t267 * 0.0011395919218959709 - d19 * t264 *
      0.00021069892662948649) + d13 * t263 * 0.0022791838437919432) + d * ct_idx_224 * 0.0001074061773490875)) + (((d2 *
      ct_idx_222 * -6.2929081251992893E-5 - d14 * t268 * 0.0011395919218959709) + d17 * t267 * 0.0011395919218959709) -
      d12 * t268 * 0.0011395919218959709)) + (((d15 * t267 * -0.0011395919218959709 - d8 * ct_idx_225 *
      0.002140376511573634) + d2 * ct_idx_224 * 5.3703088674543732E-5) - d4 * ct_idx_222 * 6.2929081251992893E-5)) +
              (((d17 * t268 * 0.0011395919218959709 - d15 * t268 * 0.0011395919218959709) + d18 * t267 *
                0.0011395919218959709) - d16 * t267 * 0.0011395919218959709)) + (((d8 * ct_idx_226 *
                -0.0052249677423607142 - d9 * ct_idx_225 * 0.002140376511573634) + d4 * ct_idx_224 *
               5.3703088674543732E-5) + d18 * t268 * 0.0011395919218959709)) + (((d16 * t268 * -0.0011395919218959709 +
               d19 * t267 * 0.0011395919218959709) - d9 * ct_idx_226 * 0.0052249677423607142) - d * ct_idx_225 *
             0.001070188255786817)) + (((d19 * t268 * 0.0011395919218959709 - d * ct_idx_226 * 0.0026124838711803571) +
             d2 * ct_idx_225 * 0.001070188255786817) + d8 * ct_idx_227 * 0.0044914180015708551)) + (((d8 * ct_idx_228 *
             0.006122597930832193 + d9 * ct_idx_227 * 0.0044914180015708551) + d4 * ct_idx_226 * 0.0026124838711803571)
           + d9 * ct_idx_228 * 0.006122597930832193)) + (((d * ct_idx_227 * 0.002245709000785428 + d * ct_idx_228 *
            0.0030612989654160969) - d2 * ct_idx_227 * 0.002245709000785428) + d10 * t279 * 0.0010036519001381671)) +
        (((d4 * ct_idx_228 * -0.0030612989654160969 + d10 * t280 * 0.00049379245033478677) + d11 * t279 *
          0.0010036519001381671) + d10 * t281 * 0.000856507133413574)) + (((d11 * t280 * 0.00049379245033478677 - d14 *
          t279 * 0.00087779373763418168) + d12 * t279 * 0.0010036519001381671) - d10 * t282 * 0.0022791838437919432)) +
      (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
      ((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((d11 * t281 * 0.000856507133413574 - d14 * t280 *
      0.00049379245033478677) - d17 * t279 * 0.00038400128729939491) + d12 * t280 * 0.00049379245033478677) + (((d15 *
      t279 * -0.00087779373763418168 - d8 * ct_idx_236 * 0.003837110775246145) + d10 * t283 * 0.00042139785325897292) -
      d11 * t282 * 0.0022791838437919432)) + (((d14 * t281 * -0.00074910095606448663 - d17 * t280 *
      0.00024689622516739339) + d12 * t281 * 0.000856507133413574) - d15 * t280 * 0.00049379245033478677)) + (((d18 *
      t279 * -0.00038400128729939491 - d16 * t279 * 0.00087779373763418168) - d9 * ct_idx_236 * 0.003837110775246145) +
      d10 * t284 * 0.0011395919218959709)) + (((d11 * t283 * 0.00042139785325897292 - d17 * t281 * 0.0003277031028055136)
      - d12 * t282 * 0.0022791838437919432) - d15 * t281 * 0.00074910095606448663)) + (((d18 * t280 *
      -0.00024689622516739339 - d16 * t280 * 0.00049379245033478677) - d19 * t279 * 0.00038400128729939491) - d *
      ct_idx_236 * 0.003837110775246145)) + (((d11 * t284 * 0.0011395919218959709 - d14 * t283 * 0.00042139785325897292)
      + d17 * t282 * 0.0022791838437919432) + d12 * t283 * 0.00042139785325897292)) + (((d18 * t281 *
      -0.0003277031028055136 - d16 * t281 * 0.00074910095606448663) - d19 * t280 * 0.00024689622516739339) + d13 * t279 *
      0.0002581431247954091)) + (((d8 * t131 * 0.000323031894834975 - d2 * ct_idx_236 * 0.003837110775246145) - d14 *
      t284 * 0.0011395919218959709) - d17 * t283 * 0.00021069892662948649)) + (((d12 * t284 * 0.0011395919218959709 -
      d15 * t283 * 0.00042139785325897292) + d18 * t282 * 0.0022791838437919432) - d19 * t281 * 0.0003277031028055136))
      + (((d8 * t154 * -0.0034187757656879139 + d9 * t131 * 0.000323031894834975) - d17 * t284 * 0.0011395919218959709)
      - d15 * t284 * 0.0011395919218959709)) + (((d18 * t283 * -0.00021069892662948649 - d16 * t283 *
      0.00042139785325897292) + d19 * t282 * 0.0022791838437919432) + d13 * t281 * 0.00022029692545642621)) + (((d8 *
      t22 * 0.0026124838711803571 - d9 * t154 * 0.0034187757656879139) + d * t131 * 0.000323031894834975) - d18 * t284 *
      0.0011395919218959709)) + (((d16 * t284 * -0.0011395919218959709 - d19 * t283 * 0.00021069892662948649) + d13 *
      t282 * 0.0022791838437919432) - d8 * t244 * 0.0026124838711803571)) + (((d9 * t22 * 0.0026124838711803571 - d *
      t154 * 0.0034187757656879139) + d2 * t131 * 0.000323031894834975) - d19 * t284 * 0.0011395919218959709)) + (((d8 *
      t133 * -0.0030612989654160969 - d9 * t244 * 0.0026124838711803571) + d * t22 * 0.001306241935590179) - d8 * t153 *
      0.0030612989654160969)) + (((d9 * t133 * -0.0030612989654160969 - d * t244 * 0.001306241935590179) + d2 * t22 *
      0.001306241935590179) - d4 * t154 * 0.0034187757656879139)) + (((d9 * t153 * -0.0030612989654160969 - d * t133 *
      0.001530649482708048) + d2 * t244 * 0.001306241935590179) - d4 * t22 * 0.001306241935590179)) + (((d * t153 *
      -0.001530649482708048 - d2 * t133 * 0.001530649482708048) - d4 * t244 * 0.001306241935590179) + d2 * t153 *
      0.001530649482708048)) + (((d4 * t133 * 0.001530649482708048 - d4 * t153 * 0.001530649482708048) + d8 * t140 *
      0.0014233180853140659) + d8 * t50 * 0.003837110775246145)) + (((d9 * t140 * 0.0014233180853140659 + d8 * t90 *
      0.001239301225677545) + d9 * t50 * 0.003837110775246145) + d * t140 * 0.0014233180853140659)) + (((d9 * t90 *
      0.001239301225677545 + d * t50 * 0.003837110775246145) - d2 * t140 * 0.000711659042657033) + d * t90 *
      0.001239301225677545)) + (((d2 * t50 * -0.003837110775246145 - d4 * t90 * 0.00061965061283877248) + d8 * t152 *
      0.0026853993625334878) + d8 * t55 * 0.000323031894834975)) + (((d9 * t152 * 0.0026853993625334878 + d8 * t76 *
      0.001057608061216121) + d9 * t55 * 0.000323031894834975) + d * t152 * 0.0026853993625334878)) + (((d8 * t122 *
      -0.0034187757656879139 + d9 * t76 * 0.001057608061216121) + d * t55 * 0.000323031894834975) - d2 * t152 *
      0.0013426996812667439)) + (((d8 * t118 * 0.002800330419650463 - d9 * t122 * 0.0034187757656879139) + d * t76 *
      0.001057608061216121) - d2 * t55 * 0.000323031894834975)) + (((d8 * t109 * -0.0032814168581358342 + d9 * t118 *
      0.0014001652098252319) - d * t122 * 0.0034187757656879139) + d8 * t51 * 0.00024689622516739339)) + (((d9 * t109 *
      -0.0016407084290679171 + d * t118 * 0.0014001652098252319) - d4 * t76 * 0.00052880403060806037) - d8 * ct_idx_257 *
      0.0022791838437919432)) + (((d9 * t51 * 0.00024689622516739339 - d * t109 * 0.0016407084290679171) - d2 * t118 *
      0.0014001652098252319) + d4 * t122 * 0.0034187757656879139)) + (((d8 * t121 * -0.00021069892662948649 - d9 *
      ct_idx_257 * 0.0022791838437919432) + d * t51 * 0.00024689622516739339) + d2 * t109 * 0.0016407084290679171)) +
      (((d4 * t118 * -0.0014001652098252319 - d9 * t121 * 0.00021069892662948649) - d * ct_idx_257 *
      0.0022791838437919432) + d2 * t51 * 0.00024689622516739339)) + (((d4 * t109 * 0.0016407084290679171 - d * t121 *
      0.00021069892662948649) - d2 * ct_idx_257 * 0.0011395919218959709) + d4 * t51 * 0.00012344811258369669)) + (((d8 *
      t124 * -0.001113443063173559 - d2 * t121 * 0.00021069892662948649) - d4 * ct_idx_257 * 0.0022791838437919432) - d8
      * t13 * 0.001113443063173559)) + (((d9 * t124 * -0.001113443063173559 - d4 * t121 * 0.0001053494633147432) - d8 *
      t137 * 0.00024689622516739339) - d9 * t13 * 0.001113443063173559)) + (((d * t124 * -0.001113443063173559 - d8 *
      t52 * 0.00095020188386703329) - d9 * t137 * 0.00024689622516739339) - d * t13 * 0.001113443063173559)) + (((d2 *
      t124 * -0.00055672153158677973 + d8 * t15 * 0.00095020188386703329) - d9 * t52 * 0.00095020188386703329) - d *
      t137 * 0.00024689622516739339)) + (((d2 * t13 * 0.00055672153158677973 + d4 * t124 * 0.00055672153158677973) + d8 *
      ct_idx_265 * 0.0022791838437919432) + d9 * t15 * 0.00095020188386703329)) + (((d * t52 * -0.00095020188386703329 +
      d2 * t137 * 0.00024689622516739339) - d4 * t13 * 0.00055672153158677973) + d8 * t106 * 0.00021069892662948649)) +
      (((d9 * ct_idx_265 * 0.0022791838437919432 + d * t15 * 0.00095020188386703329) - d2 * t52 * 0.00047510094193351659)
      - d4 * t137 * 0.00012344811258369669)) + (((d9 * t106 * 0.00021069892662948649 + d * ct_idx_265 *
      0.0022791838437919432) - d2 * t15 * 0.00047510094193351659) + d4 * t52 * 0.00047510094193351659)) + (((d * t106 *
      0.00021069892662948649 + d2 * ct_idx_265 * 0.0011395919218959709) + d4 * t15 * 0.00047510094193351659) - d2 * t106
      * 0.00021069892662948649)) + (((d4 * ct_idx_265 * -0.0022791838437919432 + d4 * t106 * 0.0001053494633147432) + d8
      * t107 * 0.0026124838711803571) - d8 * t105 * 0.0030612989654160969)) + (((d9 * t107 * 0.0026124838711803571 - d8 *
      ct_idx_270 * 0.00056979596094798557) - d9 * t105 * 0.0030612989654160969) + d * t107 * 0.001306241935590179)) +
      (((d9 * ct_idx_270 * -0.00056979596094798557 - d * t105 * 0.001530649482708048) - d2 * t107 * 0.001306241935590179)
      - d * ct_idx_270 * 0.00056979596094798557)) + (((d2 * t105 * 0.001530649482708048 - d4 * t107 *
      0.001306241935590179) - d2 * ct_idx_270 * 0.00056979596094798557) + d4 * t105 * 0.001530649482708048)) + (((d4 *
      ct_idx_270 * -0.00056979596094798557 + d8 * t77 * 0.00024689622516739339) - d8 * ct_idx_272 *
      0.0022791838437919432) + d9 * t77 * 0.00024689622516739339)) + (((d8 * t86 * 0.00021069892662948649 - d9 *
      ct_idx_272 * 0.0022791838437919432) + d * t77 * 0.00024689622516739339) - d8 * ct_idx_274 * 0.00056979596094798557))
      + (((d9 * t86 * 0.00021069892662948649 - d * ct_idx_272 * 0.0022791838437919432) + d2 * t77 *
      0.00024689622516739339) - d8 * ct_idx_275 * 0.00056979596094798557)) + (((d9 * ct_idx_274 *
      -0.00056979596094798557 + d * t86 * 0.00021069892662948649) + d2 * ct_idx_272 * 0.0011395919218959709) - d4 * t77 *
      0.00012344811258369669)) + (((d8 * t14 * -0.00012585816250398581 - d9 * ct_idx_275 * 0.00056979596094798557) - d *
      ct_idx_274 * 0.00056979596094798557) + d2 * t86 * 0.00021069892662948649)) + (((d4 * ct_idx_272 *
      -0.0022791838437919432 - d8 * t84 * 0.00024689622516739339) - d9 * t14 * 0.00012585816250398581) - d * ct_idx_275 *
      0.00056979596094798557)) + (((d2 * ct_idx_274 * 0.00056979596094798557 - d4 * t86 * 0.0001053494633147432) - d8 *
      t16 * 0.0001074061773490875) - d9 * t84 * 0.00024689622516739339)) + (((d * t14 * -0.00012585816250398581 - d2 *
      ct_idx_275 * 0.00056979596094798557) - d4 * ct_idx_274 * 0.00056979596094798557) + d8 * ct_idx_280 *
      0.0022791838437919432)) + (((d9 * t16 * -0.0001074061773490875 - d * t84 * 0.00024689622516739339) + d2 * t14 *
      6.2929081251992893E-5) + d4 * ct_idx_275 * 0.00056979596094798557)) + (((d8 * t19 * -0.00021069892662948649 + d9 *
      ct_idx_280 * 0.0022791838437919432) - d * t16 * 0.0001074061773490875) + d2 * t84 * 0.00024689622516739339)) +
      (((d4 * t14 * 6.2929081251992893E-5 - d8 * ct_idx_282 * 0.00056979596094798557) - d9 * t19 *
      0.00021069892662948649) + d * ct_idx_280 * 0.0022791838437919432)) + (((d2 * t16 * 5.3703088674543732E-5 + d4 *
      t84 * 0.00012344811258369669) - d9 * ct_idx_282 * 0.00056979596094798557) - d * t19 * 0.00021069892662948649)) +
      (((d2 * ct_idx_280 * -0.0011395919218959709 + d4 * t16 * 5.3703088674543732E-5) - d * ct_idx_282 *
      0.00056979596094798557) + d2 * t19 * 0.00021069892662948649)) + (((d4 * ct_idx_280 * -0.0022791838437919432 + d2 *
      ct_idx_282 * 0.00056979596094798557) + d4 * t19 * 0.0001053494633147432) + d4 * ct_idx_282 *
      0.00056979596094798557)) + (((d23 * t139 * 0.015505633647177591 + d23 * t141 * 0.14236259042587629) - d24 *
      ct_idx_193 * 0.0008044397038986258) + d24 * ct_idx_194 * 0.00599579036313029)) + (((d130 * t33 *
      -0.0041253563881138069 - d131 * t33 * 0.0020229006853303322) - d5 * t43 * 0.0010114503426651661) + d7 * t43 *
      0.002062678194056903)) + (((d4 * t33 * t34 * 0.0018507243915179719 - d20 * t44 * 0.0018507243915179719) + d60 *
      t29 * 0.0041253563881138069) + d61 * t29 * 0.0020229006853303322)) + (((d65 * t29 * -0.0041253563881138069 - d66 *
      t29 * 0.0041253563881138069) - d67 * t29 * 0.0041253563881138069) - d69 * t29 * 0.0020229006853303322)) + (((d71 *
      t29 * -0.0020229006853303322 - d73 * t29 * 0.0020229006853303322) + d74 * 0.0020229006853303322) + d75 *
      0.0020229006853303322)) + (((d76 * 0.0020229006853303322 + d77 * 0.0020229006853303322) + d78 *
      0.0020229006853303322) + d79 * 0.0020229006853303322)) + (((d80 * 0.0020229006853303322 + d81 *
      0.0020229006853303322) + d82 * 0.0020229006853303322) - d84 * 0.0041253563881138069)) + (((d85 *
      -0.0041253563881138069 - d87 * 0.0041253563881138069) - d89 * 0.0041253563881138069) - d90 * 0.0041253563881138069))
      + (((d92 * -0.0041253563881138069 - d94 * 0.0041253563881138069) - d95 * 0.0041253563881138069) - d97 *
      0.0041253563881138069)) + (((d101 * -0.0020229006853303322 - d105 * 0.0020229006853303322) - d109 *
      0.0020229006853303322) + d116 * 0.0041253563881138069)) + (((d121 * 0.0041253563881138069 + d126 *
      0.0041253563881138069) + d110 * t4 * t34 * 0.0074028975660718876) - d42 * t8 * t9 * t34 * 0.0074028975660718876))
      + (((d111 * t7 * t9 * t34 * -0.0074028975660718876 - d142 * t7 * t8 * t34 * 0.0074028975660718876) - d112 * t44 *
      0.0037014487830359438) - d113 * t44 * 0.0037014487830359438)) + (((d114 * t44 * -0.0037014487830359438 - d117 *
      t44 * 0.0037014487830359438) - d118 * t44 * 0.0037014487830359438) - d119 * t44 * 0.0037014487830359438)) +
      (((d122 * t44 * -0.0037014487830359438 - d123 * t44 * 0.0037014487830359438) - d124 * t44 * 0.0037014487830359438)
      + d127 * t44 * 0.0037014487830359438)) + (((d128 * t44 * 0.0037014487830359438 + d129 * t44 *
      0.0037014487830359438) - d132 * t34 * 0.0055521731745539161) + d133 * ct_idx_291 * t44 * 0.0055521731745539161)) +
      (((d134 * ct_idx_290 * t44 * 0.0055521731745539161 + d135 * t40 * t44 * 0.0055521731745539161) + d136 * ct_idx_291
      * t44 * 0.0055521731745539161) + d46 * ct_idx_290 * t44 * 0.0055521731745539161)) + (((d137 * t40 * t44 *
      0.0055521731745539161 + d138 * ct_idx_291 * t44 * 0.0055521731745539161) + d47 * ct_idx_290 * t44 *
      0.0055521731745539161) + d139 * t40 * t44 * 0.0055521731745539161)) + (((d48 * t34 * ct_idx_290 * ct_idx_291 *
      0.0055521731745539161 + d140 * t34 * t40 * ct_idx_291 * 0.0055521731745539161) + d141 * t34 * t40 * ct_idx_290 *
      0.0055521731745539161) - d22 * ct_idx_290 * ct_idx_291 * t44 * 0.0055521731745539161)) + (((d9 * t40 * ct_idx_290 *
      ct_idx_291 * t44 * -0.0055521731745539161 - d * t40 * ct_idx_290 * ct_idx_291 * t44 * 0.0055521731745539161) + d51
      * t25 * 0.0020229006853303322) + d55 * t25 * 0.0020229006853303322)) + (((d59 * t25 * 0.0020229006853303322 + d51 *
      t26 * 0.0020229006853303322) + d55 * t26 * 0.0020229006853303322) + d59 * t26 * 0.0020229006853303322)) + (((d51 *
      t27 * 0.0020229006853303322 + d55 * t27 * 0.0020229006853303322) + d59 * t27 * 0.0020229006853303322) - d51 * t28 *
      0.0020229006853303322)) + (((d55 * t28 * -0.0020229006853303322 - d59 * t28 * 0.0020229006853303322) + d51 * t29 *
      0.0020229006853303322) + d55 * t29 * 0.0020229006853303322)) + (((d59 * t29 * 0.0020229006853303322 - d143 * t25 *
      0.0041253563881138069) - d144 * t25 * 0.0041253563881138069) - d145 * t25 * 0.0041253563881138069)) + (((d143 *
      t26 * -0.0041253563881138069 - d144 * t26 * 0.0041253563881138069) - d145 * t26 * 0.0041253563881138069) - d143 *
      t27 * 0.0041253563881138069)) + (((d144 * t27 * -0.0041253563881138069 - d145 * t27 * 0.0041253563881138069) +
      d143 * t28 * 0.0041253563881138069) + d144 * t28 * 0.0041253563881138069)) + (((d145 * t28 * 0.0041253563881138069
      - d143 * t29 * 0.0041253563881138069) - d144 * t29 * 0.0041253563881138069) - d145 * t29 * 0.0041253563881138069))
      + (((d147 * t25 * -0.0020229006853303322 - d147 * t26 * 0.0020229006853303322) - d147 * t27 *
      0.0020229006853303322) + d147 * t28 * 0.0020229006853303322)) + (((d147 * t29 * -0.0020229006853303322 + d148 *
      t25 * 0.0041253563881138069) + d148 * t26 * 0.0041253563881138069) + d148 * t27 * 0.0041253563881138069)) +
      (((d148 * t28 * -0.0041253563881138069 + d148 * t29 * 0.0041253563881138069) + d60 * t25 * t33 *
      0.0041253563881138069) + d60 * t26 * t33 * 0.0041253563881138069)) + (((d60 * t27 * t33 * 0.0041253563881138069 +
      d61 * t25 * t33 * 0.0020229006853303322) + d61 * t26 * t33 * 0.0020229006853303322) + d61 * t27 * t33 *
      0.0020229006853303322)) + (((d149 * t25 * t34 * 0.0037014487830359438 + d150 * t25 * t34 * 0.0037014487830359438)
      - d65 * t25 * t33 * 0.0041253563881138069) + d151 * t25 * t34 * 0.0037014487830359438)) + (((d66 * t25 * t33 *
      -0.0041253563881138069 - d67 * t25 * t33 * 0.0041253563881138069) + d149 * t26 * t34 * 0.0037014487830359438) +
      d150 * t26 * t34 * 0.0037014487830359438)) + (((d65 * t26 * t33 * -0.0041253563881138069 + d151 * t26 * t34 *
      0.0037014487830359438) - d66 * t26 * t33 * 0.0041253563881138069) - d67 * t26 * t33 * 0.0041253563881138069)) +
      (((d149 * t27 * t34 * 0.0037014487830359438 + d150 * t27 * t34 * 0.0037014487830359438) - d65 * t27 * t33 *
      0.0041253563881138069) + d151 * t27 * t34 * 0.0037014487830359438)) + (((d66 * t27 * t33 * -0.0041253563881138069
      - d67 * t27 * t33 * 0.0041253563881138069) - d149 * t28 * t34 * 0.0037014487830359438) - d150 * t28 * t34 *
      0.0037014487830359438)) + (((d151 * t28 * t34 * -0.0037014487830359438 - d69 * t25 * t33 * 0.0020229006853303322)
      - d71 * t25 * t33 * 0.0020229006853303322) - d73 * t25 * t33 * 0.0020229006853303322)) + (((d69 * t26 * t33 *
      -0.0020229006853303322 - d71 * t26 * t33 * 0.0020229006853303322) - d73 * t26 * t33 * 0.0020229006853303322) - d69
      * t27 * t33 * 0.0020229006853303322)) + (((d71 * t27 * t33 * -0.0020229006853303322 - d73 * t27 * t33 *
      0.0020229006853303322) - d152 * t25 * t34 * 0.0037014487830359438) - d152 * t26 * t34 * 0.0037014487830359438)) +
      (((d152 * t27 * t34 * -0.0037014487830359438 + d152 * t28 * t34 * 0.0037014487830359438) + d26 * t25 * t43 * t44 *
      0.0018507243915179719) + d26 * t26 * t43 * t44 * 0.0018507243915179719)) + (((d26 * t27 * t43 * t44 *
      0.0018507243915179719 - d68 * t25 * t43 * t44 * 0.0018507243915179719) - d70 * t25 * t43 * t44 *
      0.0018507243915179719) - d72 * t25 * t43 * t44 * 0.0018507243915179719)) + (((d68 * t26 * t43 * t44 *
      -0.0018507243915179719 - d70 * t26 * t43 * t44 * 0.0018507243915179719) - d72 * t26 * t43 * t44 *
      0.0018507243915179719) - d68 * t27 * t43 * t44 * 0.0018507243915179719)) + (((d70 * t27 * t43 * t44 *
      -0.0018507243915179719 - d72 * t27 * t43 * t44 * 0.0018507243915179719) + d156 * t6 * 0.0082507127762276138) +
      d157 * t6 * 0.0082507127762276138)) + (((d159 * t6 * t9 * 0.0040458013706606644 + d161 * t6 * t8 *
      0.0040458013706606644) + d164 * t6 * t7 * 0.0040458013706606644) + d165 * t6 * 0.0082507127762276138)) + (((d167 *
      t6 * t9 * 0.0040458013706606644 + d169 * t6 * t8 * 0.0040458013706606644) + d172 * t6 * t7 * 0.0040458013706606644)
      + d174 * t6 * t9 * 0.0040458013706606644)) + (((d176 * t6 * t8 * 0.0040458013706606644 + d179 * t6 * t7 *
      0.0040458013706606644) + d156 * t11 * 0.0040458013706606644) + d157 * t11 * 0.0040458013706606644)) + (((d159 * t9
      * t11 * -0.0082507127762276138 - d161 * t8 * t11 * 0.0082507127762276138) - d164 * t7 * t11 *
      0.0082507127762276138) + d165 * t11 * 0.0040458013706606644)) + (((d167 * t9 * t11 * -0.0082507127762276138 - d169
      * t8 * t11 * 0.0082507127762276138) - d172 * t7 * t11 * 0.0082507127762276138) - d174 * t9 * t11 *
      0.0082507127762276138)) + (((d176 * t8 * t11 * -0.0082507127762276138 - d179 * t7 * t11 * 0.0082507127762276138) -
      d180 * t6 * t8 * t9 * 0.0082507127762276138) - d181 * t6 * t7 * t9 * 0.0082507127762276138)) + (((d212 * t7 * t8 *
      -0.0082507127762276138 - d184 * t6 * t8 * t9 * 0.0082507127762276138) - d185 * t6 * t7 * t9 *
      0.0082507127762276138) - d213 * t7 * t8 * 0.0082507127762276138)) + (((d221 * t7 * t8 * t9 *
      -0.0040458013706606644 - d189 * t6 * t8 * t9 * 0.0082507127762276138) - d190 * t6 * t7 * t9 *
      0.0082507127762276138) - d214 * t7 * t8 * 0.0082507127762276138)) + (((d215 * t7 * t8 * t9 *
      -0.0040458013706606644 - d216 * t7 * t8 * t9 * 0.0040458013706606644) - d180 * t8 * t9 * t11 *
      0.0040458013706606644) - d181 * t7 * t9 * t11 * 0.0040458013706606644)) + (((d183 * t7 * t8 * t11 *
      -0.0040458013706606644 - d184 * t8 * t9 * t11 * 0.0040458013706606644) - d185 * t7 * t9 * t11 *
      0.0040458013706606644) - d187 * t7 * t8 * t11 * 0.0040458013706606644)) + (((d188 * t7 * t8 * t9 * t11 *
      0.0082507127762276138 - d189 * t8 * t9 * t11 * 0.0040458013706606644) - d190 * t7 * t9 * t11 *
      0.0040458013706606644) - d192 * t7 * t8 * t11 * 0.0040458013706606644)) + (((d193 * t7 * t8 * t9 * t11 *
      0.0082507127762276138 + d194 * t7 * t8 * t9 * t11 * 0.0082507127762276138) + d195 * t6 * t33 *
      0.0082507127762276138) + d196 * t6 * t33 * 0.0082507127762276138)) + (((d197 * t6 * t33 * 0.0082507127762276138 +
      d195 * t11 * t33 * 0.0040458013706606644) + d196 * t11 * t33 * 0.0040458013706606644) + d197 * t11 * t33 *
      0.0040458013706606644)) + (((d74 * t33 * 0.0020229006853303322 + d75 * t33 * 0.0020229006853303322) + d76 * t33 *
      0.0020229006853303322) + d77 * t33 * 0.0020229006853303322)) + (((d78 * t33 * 0.0020229006853303322 + d79 * t33 *
      0.0020229006853303322) + d158 * t9 * t10 * t34 * 0.0074028975660718876) + d160 * t8 * t10 * t34 *
      0.0074028975660718876)) + (((d153 * t6 * t8 * t9 * t33 * -0.0082507127762276138 + d163 * t7 * t10 * t34 *
      0.0074028975660718876) - d162 * t6 * t7 * t9 * t33 * 0.0082507127762276138) - d220 * t7 * t8 * t33 *
      0.0082507127762276138)) + (((d80 * t33 * 0.0020229006853303322 + d81 * t33 * 0.0020229006853303322) + d82 * t33 *
      0.0020229006853303322) + d166 * t9 * t10 * t34 * 0.0074028975660718876)) + (((d168 * t8 * t10 * t34 *
      0.0074028975660718876 - d154 * t6 * t8 * t9 * t33 * 0.0082507127762276138) + d171 * t7 * t10 * t34 *
      0.0074028975660718876) - d170 * t6 * t7 * t9 * t33 * 0.0082507127762276138)) + (((d210 * t7 * t8 * t33 *
      -0.0082507127762276138 + d173 * t9 * t10 * t34 * 0.0074028975660718876) + d175 * t8 * t10 * t34 *
      0.0074028975660718876) - d155 * t6 * t8 * t9 * t33 * 0.0082507127762276138)) + (((d178 * t7 * t10 * t34 *
      0.0074028975660718876 - d177 * t6 * t7 * t9 * t33 * 0.0082507127762276138) - d211 * t7 * t8 * t33 *
      0.0082507127762276138) - d84 * t33 * 0.0041253563881138069)) + (((d85 * t33 * -0.0041253563881138069 - d87 * t33 *
      0.0041253563881138069) - d89 * t33 * 0.0041253563881138069) - d90 * t33 * 0.0041253563881138069)) + (((d92 * t33 *
      -0.0041253563881138069 - d201 * t11 * t33 * 0.0040458013706606644) - d202 * t11 * t33 * 0.0040458013706606644) -
      d203 * t11 * t33 * 0.0040458013706606644)) + (((d94 * t33 * -0.0041253563881138069 - d95 * t33 *
      0.0041253563881138069) - d97 * t33 * 0.0041253563881138069) - d204 * t11 * t33 * 0.0040458013706606644)) + (((d205
      * t11 * t33 * -0.0040458013706606644 - d206 * t11 * t33 * 0.0040458013706606644) - d98 * t6 * t9 * t43 *
      0.0082507127762276138) - d43 * t6 * t8 * t43 * 0.0082507127762276138)) + (((d217 * t7 * t43 *
      -0.0082507127762276138 - d207 * t11 * t33 * 0.0040458013706606644) - d208 * t11 * t33 * 0.0040458013706606644) -
      d209 * t11 * t33 * 0.0040458013706606644)) + (((d30 * t10 * t44 * 0.0074028975660718876 - d101 * t33 *
      0.0020229006853303322) - d102 * t6 * t9 * t43 * 0.0082507127762276138) - d44 * t6 * t8 * t43 *
      0.0082507127762276138)) + (((d218 * t7 * t43 * -0.0082507127762276138 + d34 * t10 * t44 * 0.0074028975660718876) -
      d105 * t33 * 0.0020229006853303322) - d106 * t6 * t9 * t43 * 0.0082507127762276138)) + (((d45 * t6 * t8 * t43 *
      -0.0082507127762276138 - d219 * t7 * t43 * 0.0082507127762276138) - d10 * t7 * t8 * t9 * t10 * t34 *
      0.0074028975660718876) + d38 * t10 * t44 * 0.0074028975660718876)) + (((d109 * t33 * -0.0020229006853303322 - d11 *
      t7 * t8 * t9 * t10 * t34 * 0.0074028975660718876) - d110 * t5 * t9 * t44 * 0.0074028975660718876) - d42 * t4 * t5 *
      t8 * t44 * 0.0074028975660718876)) + (((d111 * t4 * t5 * t7 * t44 * -0.0074028975660718876 - d112 * t11 * t43 *
      0.0040458013706606644) - d113 * t11 * t43 * 0.0040458013706606644) - d114 * t11 * t43 * 0.0040458013706606644)) +
      (((d12 * t7 * t8 * t9 * t10 * t34 * -0.0074028975660718876 + d116 * t33 * 0.0041253563881138069) - d117 * t11 *
      t43 * 0.0040458013706606644) - d118 * t11 * t43 * 0.0040458013706606644)) + (((d119 * t11 * t43 *
      -0.0040458013706606644 + d121 * t33 * 0.0041253563881138069) - d122 * t11 * t43 * 0.0040458013706606644) - d123 *
      t11 * t43 * 0.0040458013706606644)) + (((d124 * t11 * t43 * -0.0040458013706606644 + d126 * t33 *
      0.0041253563881138069) + d222 * t7 * t8 * t9 * t43 * 0.0082507127762276138) - d27 * t8 * t9 * t10 * t44 *
      0.0074028975660718876)) + (((d32 * t7 * t9 * t10 * t44 * -0.0074028975660718876 - d182 * t7 * t8 * t10 * t44 *
      0.0074028975660718876) + d223 * t7 * t8 * t9 * t43 * 0.0082507127762276138) - d28 * t8 * t9 * t10 * t44 *
      0.0074028975660718876)) + (((d36 * t7 * t9 * t10 * t44 * -0.0074028975660718876 - d186 * t7 * t8 * t10 * t44 *
      0.0074028975660718876) + d224 * t7 * t8 * t9 * t43 * 0.0082507127762276138) - d29 * t8 * t9 * t10 * t44 *
      0.0074028975660718876)) + (((d40 * t7 * t9 * t10 * t44 * -0.0074028975660718876 - d191 * t7 * t8 * t10 * t44 *
      0.0074028975660718876) + d13 * t5 * t7 * t8 * t9 * t44 * 0.0074028975660718876) + d127 * t11 * t43 *
      0.0040458013706606644)) + (((d128 * t11 * t43 * 0.0040458013706606644 + d129 * t11 * t43 * 0.0040458013706606644)
      + d112 * t33 * t44 * 0.0037014487830359438) + d113 * t33 * t44 * 0.0037014487830359438)) + (((d114 * t33 * t44 *
      0.0037014487830359438 + d83 * t34 * t43 * 0.0037014487830359438) + d31 * t34 * t43 * 0.0037014487830359438) + d86 *
      t34 * t43 * 0.0037014487830359438)) + (((d117 * t33 * t44 * 0.0037014487830359438 + d118 * t33 * t44 *
      0.0037014487830359438) + d119 * t33 * t44 * 0.0037014487830359438) + d88 * t34 * t43 * 0.0037014487830359438)) +
      (((d35 * t34 * t43 * 0.0037014487830359438 + d91 * t34 * t43 * 0.0037014487830359438) + d122 * t33 * t44 *
      0.0037014487830359438) + d123 * t33 * t44 * 0.0037014487830359438)) + (((d124 * t33 * t44 * 0.0037014487830359438
      + d195 * t43 * t44 * 0.0037014487830359438) + d93 * t34 * t43 * 0.0037014487830359438) + d39 * t34 * t43 *
      0.0037014487830359438)) + (((d96 * t34 * t43 * 0.0037014487830359438 + d196 * t43 * t44 * 0.0037014487830359438) +
      d197 * t43 * t44 * 0.0037014487830359438) - d127 * t33 * t44 * 0.0037014487830359438)) + (((d115 * t34 * t43 *
      -0.0037014487830359438 - d128 * t33 * t44 * 0.0037014487830359438) - d120 * t34 * t43 * 0.0037014487830359438) -
      d129 * t33 * t44 * 0.0037014487830359438)) + (((d201 * t43 * t44 * -0.0037014487830359438 - d202 * t43 * t44 *
      0.0037014487830359438) - d203 * t43 * t44 * 0.0037014487830359438) - d125 * t34 * t43 * 0.0037014487830359438)) +
      (((e_coriolis_current_tmp * ct_idx_253 * ct_idx_262 * 0.0040458013706606644 - d204 * t43 * t44 *
      0.0037014487830359438) - d205 * t43 * t44 * 0.0037014487830359438) - d206 * t43 * t44 * 0.0037014487830359438)) +
      (((f_coriolis_current_tmp * ct_idx_253 * ct_idx_262 * 0.0040458013706606644 - d207 * t43 * t44 *
      0.0037014487830359438) - d208 * t43 * t44 * 0.0037014487830359438) - d209 * t43 * t44 * 0.0037014487830359438)) +
      (((g_coriolis_current_tmp * ct_idx_253 * ct_idx_262 * 0.0040458013706606644 - h_coriolis_current_tmp * ct_idx_253 *
      ct_idx_262 * 0.0082507127762276138) - i_coriolis_current_tmp * ct_idx_253 * ct_idx_262 * 0.0082507127762276138) -
      j_coriolis_current_tmp * ct_idx_253 * ct_idx_262 * 0.0082507127762276138)) + (((coriolis_current_tmp * ct_idx_253 *
      ct_idx_291 * 0.0020229006853303322 + coriolis_current_tmp * ct_idx_262 * ct_idx_290 * 0.0020229006853303322) +
      coriolis_current_tmp_tmp * ct_idx_253 * ct_idx_262 * t40 * 0.0020229006853303322) - b_coriolis_current_tmp *
      ct_idx_253 * ct_idx_291 * 0.0041253563881138069)) + (((b_coriolis_current_tmp * ct_idx_262 * ct_idx_290 *
      -0.0041253563881138069 - b_coriolis_current_tmp_tmp * ct_idx_253 * ct_idx_262 * t40 * 0.0041253563881138069) -
      c_coriolis_current_tmp * ct_idx_253 * ct_idx_291 * 0.0041253563881138069) - c_coriolis_current_tmp * ct_idx_262 *
      ct_idx_290 * 0.0041253563881138069)) + (((c_coriolis_current_tmp_tmp * ct_idx_253 * ct_idx_262 * t40 *
      -0.0041253563881138069 - d_coriolis_current_tmp * ct_idx_253 * ct_idx_291 * 0.0020229006853303322) -
      d_coriolis_current_tmp * ct_idx_262 * ct_idx_290 * 0.0020229006853303322) - d_coriolis_current_tmp_tmp *
      ct_idx_253 * ct_idx_262 * t40 * 0.0020229006853303322)) + (((e_coriolis_current_tmp * ct_idx_290 * ct_idx_291 *
      -0.0040458013706606644 - e_coriolis_current_tmp_tmp * ct_idx_253 * t40 * ct_idx_291 * 0.0040458013706606644) -
      e_coriolis_current_tmp_tmp * ct_idx_262 * t40 * ct_idx_290 * 0.0040458013706606644) - f_coriolis_current_tmp *
      ct_idx_290 * ct_idx_291 * 0.0040458013706606644)) + (((f_coriolis_current_tmp_tmp * ct_idx_253 * t40 * ct_idx_291 *
      -0.0040458013706606644 - f_coriolis_current_tmp_tmp * ct_idx_262 * t40 * ct_idx_290 * 0.0040458013706606644) -
      g_coriolis_current_tmp * ct_idx_290 * ct_idx_291 * 0.0040458013706606644) - g_coriolis_current_tmp_tmp *
      ct_idx_253 * t40 * ct_idx_291 * 0.0040458013706606644)) + (((g_coriolis_current_tmp_tmp * ct_idx_262 * t40 *
      ct_idx_290 * -0.0040458013706606644 - l_coriolis_current_tmp * ct_idx_253 * ct_idx_262 * t34 *
      0.0074028975660718876) - n_coriolis_current_tmp * ct_idx_253 * ct_idx_262 * t34 * 0.0074028975660718876) +
      h_coriolis_current_tmp * ct_idx_290 * ct_idx_291 * 0.0082507127762276138)) + (((h_coriolis_current_tmp_tmp *
      ct_idx_253 * t40 * ct_idx_291 * 0.0082507127762276138 + h_coriolis_current_tmp_tmp * ct_idx_262 * t40 * ct_idx_290
      * 0.0082507127762276138) - p_coriolis_current_tmp * ct_idx_253 * ct_idx_262 * t34 * 0.0074028975660718876) +
      i_coriolis_current_tmp * ct_idx_290 * ct_idx_291 * 0.0082507127762276138)) + (((i_coriolis_current_tmp_tmp *
      ct_idx_253 * t40 * ct_idx_291 * 0.0082507127762276138 + i_coriolis_current_tmp_tmp * ct_idx_262 * t40 * ct_idx_290
      * 0.0082507127762276138) + r_coriolis_current_tmp * ct_idx_253 * ct_idx_262 * t33 * 0.0041253563881138069) +
      j_coriolis_current_tmp * ct_idx_290 * ct_idx_291 * 0.0082507127762276138)) + (((j_coriolis_current_tmp_tmp *
      ct_idx_253 * t40 * ct_idx_291 * 0.0082507127762276138 + j_coriolis_current_tmp_tmp * ct_idx_262 * t40 * ct_idx_290
      * 0.0082507127762276138) - coriolis_current_tmp_tmp * t40 * ct_idx_290 * ct_idx_291 * 0.0020229006853303322) +
      w_coriolis_current_tmp * ct_idx_253 * ct_idx_262 * t33 * 0.0020229006853303322)) + (((b_coriolis_current_tmp_tmp *
      t40 * ct_idx_290 * ct_idx_291 * 0.0041253563881138069 + c_coriolis_current_tmp_tmp * t40 * ct_idx_290 * ct_idx_291
      * 0.0041253563881138069) + x_coriolis_current_tmp * ct_idx_253 * ct_idx_262 * t43 * 0.0010114503426651661) +
      d_coriolis_current_tmp_tmp * t40 * ct_idx_290 * ct_idx_291 * 0.0020229006853303322)) + (((k_coriolis_current_tmp *
      ct_idx_253 * t34 * ct_idx_291 * 0.0037014487830359438 + k_coriolis_current_tmp * ct_idx_262 * t34 * ct_idx_290 *
      0.0037014487830359438) + d6 * ct_idx_253 * ct_idx_262 * t34 * t40 * 0.0037014487830359438) -
      y_coriolis_current_tmp * ct_idx_253 * ct_idx_262 * t43 * 0.002062678194056903)) + (((l_coriolis_current_tmp * t34 *
      ct_idx_290 * ct_idx_291 * 0.0074028975660718876 + k_coriolis_current_tmp_tmp * ct_idx_253 * t34 * t40 * ct_idx_291
      * 0.0074028975660718876) + k_coriolis_current_tmp_tmp * ct_idx_262 * t34 * t40 * ct_idx_290 *
      0.0074028975660718876) - m_coriolis_current_tmp * ct_idx_253 * ct_idx_291 * t43 * 0.0041253563881138069)) +
                       (((m_coriolis_current_tmp * ct_idx_262 * ct_idx_290 * t43 * -0.0041253563881138069 -
      coriolis_current_tmp_tmp_tmp * ct_idx_253 * ct_idx_262 * t40 * t43 * 0.0041253563881138069) +
                         n_coriolis_current_tmp * t34 * ct_idx_290 * ct_idx_291 * 0.0074028975660718876) +
                        l_coriolis_current_tmp_tmp * ct_idx_253 * t34 * t40 * ct_idx_291 * 0.0074028975660718876)) +
                      (((l_coriolis_current_tmp_tmp * ct_idx_262 * t34 * t40 * ct_idx_290 * 0.0074028975660718876 -
                         o_coriolis_current_tmp * ct_idx_253 * ct_idx_291 * t43 * 0.0041253563881138069) -
                        o_coriolis_current_tmp * ct_idx_262 * ct_idx_290 * t43 * 0.0041253563881138069) -
                       b_coriolis_current_tmp_tmp_tmp * ct_idx_253 * ct_idx_262 * t40 * t43 * 0.0041253563881138069)) +
                     (((p_coriolis_current_tmp * t34 * ct_idx_290 * ct_idx_291 * 0.0074028975660718876 +
                        m_coriolis_current_tmp_tmp * ct_idx_253 * t34 * t40 * ct_idx_291 * 0.0074028975660718876) +
                       m_coriolis_current_tmp_tmp * ct_idx_262 * t34 * t40 * ct_idx_290 * 0.0074028975660718876) -
                      q_coriolis_current_tmp * ct_idx_253 * ct_idx_291 * t43 * 0.0041253563881138069)) +
                    (((q_coriolis_current_tmp * ct_idx_262 * ct_idx_290 * t43 * -0.0041253563881138069 -
                       c_coriolis_current_tmp_tmp_tmp * ct_idx_253 * ct_idx_262 * t40 * t43 * 0.0041253563881138069) -
                      r_coriolis_current_tmp * t33 * ct_idx_290 * ct_idx_291 * 0.0041253563881138069) - d130 *
                     ct_idx_253 * t33 * t40 * ct_idx_291 * 0.0041253563881138069)) + (((d130 * ct_idx_262 * t33 * t40 *
      ct_idx_290 * -0.0041253563881138069 + s_coriolis_current_tmp * ct_idx_253 * ct_idx_291 * t44 *
      0.0074028975660718876) + s_coriolis_current_tmp * ct_idx_262 * ct_idx_290 * t44 * 0.0074028975660718876) +
      n_coriolis_current_tmp_tmp * ct_idx_253 * ct_idx_262 * t40 * t44 * 0.0074028975660718876)) +
                  (((t_coriolis_current_tmp * ct_idx_253 * ct_idx_291 * t43 * -0.0020229006853303322 -
                     t_coriolis_current_tmp * ct_idx_262 * ct_idx_290 * t43 * 0.0020229006853303322) - t104 * ct_idx_253
                    * ct_idx_262 * t40 * t43 * 0.0020229006853303322) - u_coriolis_current_tmp * ct_idx_253 * ct_idx_291
                   * t43 * 0.0020229006853303322)) + (((u_coriolis_current_tmp * ct_idx_262 * ct_idx_290 * t43 *
      -0.0020229006853303322 - t243 * ct_idx_253 * ct_idx_262 * t40 * t43 * 0.0020229006853303322) -
      v_coriolis_current_tmp * ct_idx_253 * ct_idx_291 * t43 * 0.0020229006853303322) - v_coriolis_current_tmp *
      ct_idx_262 * ct_idx_290 * t43 * 0.0020229006853303322)) + (((t116 * ct_idx_253 * ct_idx_262 * t40 * t43 *
      -0.0020229006853303322 - w_coriolis_current_tmp * t33 * ct_idx_290 * ct_idx_291 * 0.0020229006853303322) - d131 *
      ct_idx_253 * t33 * t40 * ct_idx_291 * 0.0020229006853303322) - d131 * ct_idx_262 * t33 * t40 * ct_idx_290 *
      0.0020229006853303322)) + (((d132 * t33 * t34 * -0.0018507243915179719 - x_coriolis_current_tmp * ct_idx_290 *
      ct_idx_291 * t43 * 0.0010114503426651661) - d5 * ct_idx_253 * t40 * ct_idx_291 * t43 * 0.0010114503426651661) - d5
                * ct_idx_262 * t40 * ct_idx_290 * t43 * 0.0010114503426651661)) + (((d6 * t34 * t40 * ct_idx_290 *
      ct_idx_291 * -0.0037014487830359438 + y_coriolis_current_tmp * ct_idx_290 * ct_idx_291 * t43 *
      0.002062678194056903) + d7 * ct_idx_253 * t40 * ct_idx_291 * t43 * 0.002062678194056903) + d7 * ct_idx_262 * t40 *
               ct_idx_290 * t43 * 0.002062678194056903)) + (((coriolis_current_tmp_tmp_tmp * t40 * ct_idx_290 *
                ct_idx_291 * t43 * 0.0041253563881138069 + b_coriolis_current_tmp_tmp_tmp * t40 * ct_idx_290 *
                ct_idx_291 * t43 * 0.0041253563881138069) + c_coriolis_current_tmp_tmp_tmp * t40 * ct_idx_290 *
               ct_idx_291 * t43 * 0.0041253563881138069) - n_coriolis_current_tmp_tmp * t40 * ct_idx_290 * ct_idx_291 *
              t44 * 0.0074028975660718876)) + (((t104 * t40 * ct_idx_290 * ct_idx_291 * t43 * 0.0020229006853303322 +
               t243 * t40 * ct_idx_290 * ct_idx_291 * t43 * 0.0020229006853303322) + t116 * t40 * ct_idx_290 *
              ct_idx_291 * t43 * 0.0020229006853303322) + d133 * t33 * ct_idx_291 * t44 * 0.0018507243915179719)) +
           (((d134 * t33 * ct_idx_290 * t44 * 0.0018507243915179719 + d135 * t33 * t40 * t44 * 0.0018507243915179719) +
             d136 * t33 * ct_idx_291 * t44 * 0.0018507243915179719) + d46 * t33 * ct_idx_290 * t44 *
            0.0018507243915179719)) + (((d137 * t33 * t40 * t44 * 0.0018507243915179719 + d138 * t33 * ct_idx_291 * t44 *
             0.0018507243915179719) + d47 * t33 * ct_idx_290 * t44 * 0.0018507243915179719) + d139 * t33 * t40 * t44 *
           0.0018507243915179719)) + (((ab_coriolis_current_tmp * ct_idx_253 * ct_idx_262 * t43 * t44 *
            0.0018507243915179719 + d48 * t33 * t34 * ct_idx_290 * ct_idx_291 * 0.0018507243915179719) + d140 * t33 *
           t34 * t40 * ct_idx_291 * 0.0018507243915179719) + d141 * t33 * t34 * t40 * ct_idx_290 * 0.0018507243915179719))
        + (((d8 * t33 * t40 * ct_idx_290 * ct_idx_291 * t44 * -0.0018507243915179719 - d9 * t33 * t40 * ct_idx_290 *
             ct_idx_291 * t44 * 0.0018507243915179719) - d * t33 * t40 * ct_idx_290 * ct_idx_291 * t44 *
            0.0018507243915179719) - ab_coriolis_current_tmp * ct_idx_290 * ct_idx_291 * t43 * t44 *
           0.0018507243915179719)) + (d2 * ct_idx_253 * t40 * ct_idx_291 * t43 * t44 * -0.0018507243915179719 - d2 *
        ct_idx_262 * t40 * ct_idx_290 * t43 * t44 * 0.0018507243915179719));
    d6 = t11 * t4;
    d7 = t5 * t9;
    d20 = t11 * t5;
    d21 = t10 * t6;
    d22 = t10 * t11;
    d23 = t28 * t5;
    d24 = d13 * t10;
    d27 = d14 * t11;
    d28 = d15 * t11;
    d29 = d16 * t11;
    d30 = d17 * t11;
    d31 = d18 * t11;
    d34 = d19 * t11;
    d35 = d14 * t43;
    d38 = d15 * t43;
    d39 = d16 * t43;
    d42 = d64 * ct_idx_199;
    d43 = d146 * ct_idx_199;
    d44 = d6 * ct_idx_199;
    d45 = d20 * ct_idx_199;
    d46 = d21 * ct_idx_199;
    d47 = d22 * ct_idx_199;
    d48 = ct_idx_199 * t30;
    d51 = ct_idx_199 * t40;
    d55 = d14 * t4;
    d59 = d15 * t4;
    d3 *= t7;
    d61 = d16 * t4;
    d65 = d193 * t9;
    d66 = d55 * t10;
    d67 = d194 * t9;
    d68 = d10 * t8;
    d69 = d59 * t10;
    d70 = d61 * t10;
    d71 = d13 * t6;
    d72 = t27 * t4;
    d73 = t27 * t9;
    d74 = t10 * t28;
    d75 = t27 * t47;
    d76 = t28 * t47;
    d77 = ct_idx_199 * t88;
    d78 = ct_idx_199 * t92;
    d79 = t112 * t27;
    d80 = t112 * t28;
    d81 = t130 * ct_idx_199;
    d82 = t135 * ct_idx_199;
    d83 = t139 * ct_idx_199;
    d84 = t141 * ct_idx_199;
    d85 = t170 * ct_idx_199;
    d86 = t187 * ct_idx_199;
    d87 = t190 * ct_idx_199;
    d88 = t210 * ct_idx_199;
    d89 = ct_idx_193 * ct_idx_199;
    d90 = ct_idx_194 * ct_idx_199;
    d91 = ct_idx_195 * ct_idx_199;
    d92 = ct_idx_199 * ct_idx_208;
    d93 = ct_idx_199 * ct_idx_210;
    d94 = ct_idx_199 * ct_idx_225;
    d95 = ct_idx_199 * ct_idx_236;
    d96 = ct_idx_199 * t131;
    d97 = ct_idx_199 * t140;
    d98 = ct_idx_199 * t50;
    d101 = ct_idx_199 * t152;
    d102 = ct_idx_199 * t55;
    d105 = d11 * t9;
    d106 = d12 * t9;
    d109 = d14 * t33;
    d110 = d15 * t33;
    d112 = d17 * t34;
    d113 = d16 * t33;
    d114 = d18 * t34;
    d115 = d19 * t34;
    d116 = d17 * t44;
    d117 = d11 * t47;
    d118 = d18 * t44;
    d119 = d14 * t47;
    d120 = d12 * t47;
    d121 = d15 * t47;
    d122 = d16 * t47;
    d123 = d19 * t44;
    d124 = d2 * t69;
    d125 = d2 * t78;
    d126 = d2 * t95;
    d127 = d2 * t100;
    d128 = d11 * t112;
    d129 = d14 * t112;
    d131 = d12 * t112;
    d132 = d15 * t112;
    d133 = d16 * t112;
    d134 = d2 * t143;
    d135 = d2 * t169;
    d136 = d2 * t175;
    d137 = d2 * t191;
    d138 = d2 * t192;
    d139 = d2 * t202;
    d140 = d2 * t203;
    d141 = d64 * t27;
    d143 = d64 * t29;
    d144 = d146 * t28;
    d145 = d146 * t29;
    d147 = d7 * t27;
    d148 = d6 * t27;
    d149 = d7 * t28;
    d150 = d6 * t29;
    d151 = d20 * t28;
    d152 = d21 * t28;
    d20 *= t29;
    d21 *= t29;
    d153 = d22 * t28;
    d22 *= t29;
    d154 = d23 * t34;
    d155 = d23 * t44;
    d156 = d199 * t11;
    d157 = d200 * t11;
    d158 = d100 * t9;
    d159 = d104 * t9;
    d160 = d108 * t9;
    d161 = d71 * t10;
    d164 = d17 * t9 * t11;
    d165 = d18 * t9 * t11;
    d166 = d19 * t9 * t11;
    d167 = d24 * t11;
    d168 = d222 * t33;
    d169 = d223 * t33;
    d172 = d224 * t33;
    d173 = d27 * t33;
    d174 = d28 * t33;
    d175 = d29 * t33;
    d176 = d24 * t34;
    d179 = d100 * t43;
    d180 = d104 * t43;
    d181 = d108 * t43;
    d184 = d30 * t43;
    d185 = d31 * t43;
    d189 = d34 * t43;
    d190 = d24 * t44;
    d195 = d17 * t33;
    d196 = d195 * t34;
    d197 = d18 * t33;
    d201 = d197 * t34;
    d202 = d19 * t33;
    d203 = d202 * t34;
    d204 = d14 * t34 * t43;
    d195 *= t44;
    d197 *= t44;
    d205 = d16 * t34 * t43;
    d206 = d56 * t6;
    d207 = t4 * t5;
    d208 = d56 * t11;
    d209 = t3 * t5;
    t71 = d209 * t9;
    t72 = d207 * t8;
    t73 = d146 * t9;
    t48 = t6 * t8 * t9;
    t49 = d7 * t11;
    t60 = t8 * t9;
    t61 = t60 * t11;
    t87 = d2 * t2;
    t12 = d2 * t3;
    d225 = d17 * t5;
    d226 = d18 * t5;
    d227 = d19 * t5;
    d62 *= t7;
    d228 = d209 * t6;
    t52 = d228 * t9;
    d229 = d207 * t6;
    t54 = d229 * t8;
    d230 = d63 * t8;
    t117 = t2 * t7;
    t120 = t71 * t11;
    t121 = t72 * t11;
    t124 = t3 * t8;
    d231 = d206 * ct_idx_199;
    t13 = d62 * ct_idx_199;
    t137 = d230 * ct_idx_199;
    d232 = d208 * ct_idx_199;
    d233 = d64 * t9;
    t109 = d233 * ct_idx_199;
    d234 = t73 * ct_idx_199;
    t51 = t117 * t11 * ct_idx_199;
    t122 = t124 * t11 * ct_idx_199;
    d235 = t48 * ct_idx_199;
    t118 = t4 * t9 * t11 * ct_idx_199;
    d236 = t49 * ct_idx_199;
    d237 = t61 * ct_idx_199;
    t104 = d42 * ct_idx_283;
    t243 = d43 * ct_idx_283;
    t116 = d43 * ct_idx_284;
    t55 = d44 * ct_idx_283;
    t76 = d45 * ct_idx_283;
    t152 = d46 * ct_idx_283;
    t153 = d45 * ct_idx_284;
    t140 = d46 * ct_idx_284;
    t50 = d47 * ct_idx_283;
    t90 = d47 * ct_idx_284;
    d238 = d48 * ct_idx_253;
    d239 = d48 * ct_idx_262;
    d240 = ct_idx_199 * ct_idx_253;
    d241 = d240 * ct_idx_262;
    d242 = d238 * ct_idx_291;
    d243 = d239 * ct_idx_290;
    d244 = d241 * t40;
    d245 = d51 * ct_idx_290 * ct_idx_291;
    t106 = t87 * t3;
    d246 = t87 * t5;
    d247 = t12 * t5;
    t133 = d162 * t5;
    d248 = d198 * t5;
    d170 *= t5;
    t131 = d199 * t5;
    d249 = d246 * t8;
    d250 = d247 * t7;
    d177 *= t5;
    t154 = d200 * t5;
    t22 = t133 * t9;
    t244 = d248 * t8;
    t99 = d170 * t9;
    t172 = t131 * t8;
    d99 *= t10;
    t199 = d177 * t9;
    t23 = t154 * t8;
    d251 = d225 * t6;
    d103 *= t10;
    d5 *= t7;
    d252 = d226 * t6;
    d107 *= t10;
    d253 = d227 * t6;
    t201 = d4 * t7;
    t155 = d14 * t8 * t9 * t10;
    t200 = d15 * t8 * t9 * t10;
    t223 = d16 * t8 * t9 * t10;
    d254 = t106 * t9;
    t107 = t87 * t4;
    d255 = t107 * t8;
    t15 = t12 * t4;
    d256 = t15 * t7;
    d257 = d2 * t7 * t8 * t9;
    d258 = t52 * ct_idx_199;
    d259 = t54 * ct_idx_199;
    t75 = d62 * t9 * ct_idx_199;
    t74 = d230 * t9 * ct_idx_199;
    d260 = t120 * ct_idx_199;
    d261 = t121 * ct_idx_199;
    t117 = t117 * t9 * t11 * ct_idx_199;
    t124 = t124 * t9 * t11 * ct_idx_199;
    t110 = coriolis_current_tmp_tmp * t7;
    d262 = d15 * t34 * t43;
    d202 *= t44;
    d263 = d35 * t44;
    d264 = d38 * t44;
    d265 = d39 * t44;
    d266 = t71 * ct_idx_199;
    d267 = t72 * ct_idx_199;
    d268 = t73 * t27;
    d269 = t73 * t28;
    d270 = t73 * t29;
    d271 = t49 * t27;
    d272 = t49 * t28;
    d273 = t49 * t29;
    d215 *= t9;
    d55 = d55 * t6 * t10;
    d216 *= t9;
    d183 *= t11;
    d59 = d59 * t6 * t10;
    d187 *= t11;
    d61 = d61 * t6 * t10;
    d192 *= t11;
    d274 = d65 * t11;
    d275 = d66 * t11;
    d276 = d67 * t11;
    d277 = d69 * t11;
    d278 = d70 * t11;
    d71 = d71 * t9 * t10;
    d279 = d13 * t9 * t10 * t11;
    d280 = d266 * t30;
    d281 = d267 * t30;
    d282 = d10 * t6;
    d283 = d11 * t6;
    d284 = d12 * t6;
    t20 = t13 * ct_idx_284;
    d285 = d57 * ct_idx_199 * t40;
    t21 = t137 * ct_idx_283;
    t17 = t109 * ct_idx_283;
    t18 = d234 * ct_idx_283;
    t56 = t51 * ct_idx_284;
    ct_idx_228 = t122 * ct_idx_283;
    ct_idx_236 = t118 * ct_idx_283;
    ct_idx_224 = d236 * ct_idx_283;
    t283 = t5 * t8 * t9;
    d286 = t283 * ct_idx_199 * t40;
    d7 *= ct_idx_199;
    d287 = d7 * t30 * ct_idx_253;
    d288 = d207 * ct_idx_199;
    d289 = d288 * ct_idx_253 * t40;
    d290 = ct_idx_199 * t5;
    d291 = d290 * t30;
    t84 = d4 * t2;
    d292 = t84 * t3;
    d33 *= t5;
    d293 = t84 * t4;
    t86 = d4 * t3;
    d294 = t86 * t4;
    d37 *= t5;
    d41 *= t5;
    d295 = t84 * t8;
    d296 = t86 * t7;
    ct_idx_225 = t2 * t5;
    ct_idx_226 = t243 * ct_idx_284;
    ct_idx_219 = t76 * ct_idx_284;
    ct_idx_222 = t152 * ct_idx_284;
    d297 = d46 * t30;
    ct_idx_218 = t50 * ct_idx_284;
    d298 = d291 * ct_idx_253;
    d299 = d298 * ct_idx_262;
    d300 = d47 * t30;
    d301 = d290 * ct_idx_253;
    d302 = d290 * ct_idx_262;
    d303 = d291 * ct_idx_290 * ct_idx_291;
    d304 = d301 * t40 * ct_idx_291;
    d305 = d302 * t40 * ct_idx_290;
    d306 = d238 * t33;
    d307 = d239 * t33;
    d308 = d241 * t33;
    d309 = d306 * ct_idx_291;
    d310 = d307 * ct_idx_290;
    d311 = d308 * t40;
    d312 = ct_idx_199 * t33;
    d313 = d312 * t40 * ct_idx_290 * ct_idx_291;
    d314 = t106 * t4;
    d315 = d314 * t5;
    d316 = d292 * t4;
    d246 = d246 * t6 * t8;
    d247 = d247 * t6 * t7;
    t105 = d2 * t4;
    t14 = t105 * t5;
    t77 = d4 * t4;
    d317 = d316 * t10;
    d318 = d249 * t9;
    d319 = d250 * t9;
    d320 = t14 * t7 * t8;
    t84 = t84 * t6 * t8;
    t86 = t86 * t6 * t7;
    d321 = d295 * t9;
    d322 = d321 * t10;
    d323 = d296 * t9;
    d324 = d323 * t10;
    d325 = t77 * t7 * t8;
    d326 = d325 * t10;
    d327 = d292 * t6 * t9;
    d328 = d293 * t6 * t8;
    d329 = d294 * t6 * t7;
    d330 = d292 * t9;
    d331 = d330 * t11;
    d332 = d293 * t8;
    d333 = d332 * t11;
    d334 = d294 * t7;
    d335 = d334 * t11;
    d336 = d5 * t8 * t9;
    d337 = t201 * t8 * t9;
    d338 = d337 * t11;
    d339 = d254 * t33;
    d340 = d255 * t33;
    d341 = d256 * t33;
    d342 = d257 * t33;
    d54 *= t7;
    t19 = d58 * t8;
    ct_idx_211 = d25 * t6 * t7;
    ct_idx_214 = ct_idx_225 * t6 * t7;
    d53 *= t7;
    ct_idx_215 = d52 * t6 * t7;
    t16 = d57 * t8;
    d25 *= t7;
    ct_idx_225 *= t7;
    d52 *= t7;
    ct_idx_210 = d54 * ct_idx_199;
    ct_idx_207 = t19 * ct_idx_199;
    ct_idx_208 = d53 * t11 * ct_idx_199;
    ct_idx_209 = ct_idx_214 * t10 * ct_idx_199;
    ct_idx_202 = t16 * t11 * ct_idx_199;
    d228 = d228 * t8 * t10 * ct_idx_199;
    ct_idx_204 = d229 * t9 * t10 * ct_idx_199;
    ct_idx_198 = ct_idx_225 * t10 * t11 * ct_idx_199;
    d209 = d209 * t8 * t10 * t11 * ct_idx_199;
    ct_idx_200 = d207 * t9 * t10 * t11 * ct_idx_199;
    d288 = d288 * t30 * ct_idx_290;
    d7 = d7 * t40 * ct_idx_290;
    d343 = d238 * t34 * ct_idx_291;
    d239 = d239 * t34 * ct_idx_290;
    d241 = d241 * t34 * t40;
    d344 = d242 * t44;
    d345 = d243 * t44;
    d346 = d244 * t44;
    d347 = ct_idx_199 * t34;
    d348 = d347 * t40 * ct_idx_290 * ct_idx_291;
    d349 = d245 * t44;
    d350 = d249 * t11;
    d351 = d250 * t11;
    d352 = t84 * t10;
    d353 = t86 * t10;
    d295 = d295 * t10 * t11;
    d296 = d296 * t10 * t11;
    d354 = d254 * t34;
    d355 = d255 * t34;
    d356 = d256 * t34;
    d357 = d254 * t44;
    d358 = d255 * t44;
    d359 = d256 * t44;
    d360 = d257 * t34;
    d361 = d257 * t44;
    d362 = d297 * ct_idx_253;
    d363 = d362 * ct_idx_262;
    d364 = d300 * ct_idx_253;
    d365 = d364 * ct_idx_262;
    d366 = d297 * ct_idx_290 * ct_idx_291;
    d367 = d46 * ct_idx_253;
    d368 = d367 * t40 * ct_idx_291;
    d369 = d46 * ct_idx_262 * t40 * ct_idx_290;
    d370 = d299 * t34;
    d371 = d300 * ct_idx_290 * ct_idx_291;
    d372 = d47 * ct_idx_253;
    d373 = d372 * t40 * ct_idx_291;
    d374 = d47 * ct_idx_262 * t40 * ct_idx_290;
    d375 = d299 * t44;
    d376 = d291 * t34 * ct_idx_290 * ct_idx_291;
    d377 = d248 * t6;
    d378 = ct_idx_199 * t6;
    d379 = d378 * t30;
    d380 = d379 * ct_idx_253;
    d381 = d380 * ct_idx_291;
    d382 = d379 * ct_idx_262 * ct_idx_290;
    d383 = d301 * t34 * t40 * ct_idx_291;
    d302 = d302 * t34 * t40 * ct_idx_290;
    d384 = d381 * t43;
    d385 = d382 * t43;
    d386 = t11 * ct_idx_199;
    d387 = d386 * t30;
    d388 = d378 * ct_idx_253;
    d389 = d388 * ct_idx_262 * t40;
    d390 = d387 * ct_idx_253;
    d391 = d390 * ct_idx_291;
    d392 = d387 * ct_idx_262 * ct_idx_290;
    d393 = d389 * t43;
    d394 = d391 * t43;
    d395 = d392 * t43;
    d396 = d386 * ct_idx_253;
    d397 = d396 * ct_idx_262 * t40;
    d398 = d397 * t43;
    d399 = d303 * t44;
    d400 = d304 * t44;
    d401 = d305 * t44;
    d306 = d306 * t34 * ct_idx_291;
    d307 = d307 * t34 * ct_idx_290;
    d308 = d308 * t34 * t40;
    d402 = d378 * t40 * ct_idx_290 * ct_idx_291;
    d403 = d402 * t43;
    d404 = d386 * t40 * ct_idx_290 * ct_idx_291;
    d405 = d404 * t43;
    d406 = d309 * t44;
    d407 = d310 * t44;
    d408 = d311 * t44;
    d409 = d312 * t34;
    d410 = d316 * t6;
    coriolis_current_tmp = d26 * t5;
    b_coriolis_current_tmp = t106 * t5;
    c_coriolis_current_tmp = t107 * t5;
    d_coriolis_current_tmp = t15 * t5;
    e_coriolis_current_tmp = d60 * t7 * t8;
    f_coriolis_current_tmp = d50 * t7 * t8;
    g_coriolis_current_tmp = d26 * t7 * t8;
    h_coriolis_current_tmp = d49 * t7 * t8;
    i_coriolis_current_tmp = f_coriolis_current_tmp * ct_idx_199;
    j_coriolis_current_tmp = d54 * t9 * ct_idx_199;
    k_coriolis_current_tmp = t19 * t9 * ct_idx_199;
    l_coriolis_current_tmp = h_coriolis_current_tmp * t11 * ct_idx_199;
    m_coriolis_current_tmp = ct_idx_211 * t8 * t10 * ct_idx_199;
    coriolis_current_tmp_tmp = d53 * t9;
    n_coriolis_current_tmp = coriolis_current_tmp_tmp * t11 * ct_idx_199;
    o_coriolis_current_tmp = ct_idx_215 * t9 * t10 * ct_idx_199;
    b_coriolis_current_tmp_tmp = t16 * t9;
    p_coriolis_current_tmp = b_coriolis_current_tmp_tmp * t11 * ct_idx_199;
    q_coriolis_current_tmp = d206 * t8 * t9 * t10 * ct_idx_199;
    r_coriolis_current_tmp = d25 * t8 * t10 * t11 * ct_idx_199;
    s_coriolis_current_tmp = d52 * t9 * t10 * t11 * ct_idx_199;
    t_coriolis_current_tmp = d56 * t8 * t9 * t10 * t11 * ct_idx_199;
    u_coriolis_current_tmp = ct_idx_209 * ct_idx_284;
    v_coriolis_current_tmp = d228 * ct_idx_283;
    w_coriolis_current_tmp = ct_idx_204 * ct_idx_283;
    x_coriolis_current_tmp = ct_idx_198 * ct_idx_284;
    y_coriolis_current_tmp = d209 * ct_idx_283;
    ab_coriolis_current_tmp = ct_idx_200 * ct_idx_283;
    t101 = coriolis_current_tmp * t6 * t7;
    coriolis_current_tmp *= t7;
    t102 = d409 * t40 * ct_idx_290 * ct_idx_291;
    t92 = d313 * t44;
    t81 = d315 * t6;
    t82 = d315 * t11;
    t83 = d314 * t6 * t10;
    t88 = d410 * t10;
    t89 = d314 * t10 * t11;
    t91 = d246 * t9;
    t68 = d247 * t9;
    t127 = t14 * t6 * t7 * t8;
    t103 = d317 * t11;
    t113 = d318 * t11;
    t114 = t87 * t6 * t8 * t9 * t10;
    t94 = d319 * t11;
    t96 = t12 * t6 * t7 * t9 * t10;
    t97 = d320 * t11;
    t98 = t105 * t6 * t7 * t8 * t10;
    c_coriolis_current_tmp_tmp = t84 * t9;
    t128 = c_coriolis_current_tmp_tmp * t10;
    d_coriolis_current_tmp_tmp = t86 * t9;
    t151 = d_coriolis_current_tmp_tmp * t10;
    e_coriolis_current_tmp_tmp = t77 * t6 * t7 * t8;
    t148 = e_coriolis_current_tmp_tmp * t10;
    f_coriolis_current_tmp_tmp = t87 * t8 * t9;
    t149 = f_coriolis_current_tmp_tmp * t10 * t11;
    g_coriolis_current_tmp_tmp = t12 * t7 * t9;
    t150 = g_coriolis_current_tmp_tmp * t10 * t11;
    h_coriolis_current_tmp_tmp = t105 * t7 * t8;
    t136 = h_coriolis_current_tmp_tmp * t10 * t11;
    t146 = d322 * t11;
    t253 = d324 * t11;
    t247 = d326 * t11;
    t185 = d315 * t34;
    t181 = d317 * t34;
    t168 = d327 * t33;
    t167 = d328 * t33;
    t165 = d329 * t33;
    t166 = d315 * t44;
    t164 = d318 * t34;
    t162 = d319 * t34;
    t139 = d320 * t34;
    t141 = d331 * t33;
    t145 = d333 * t33;
    t147 = d335 * t33;
    i_coriolis_current_tmp_tmp = t106 * t6 * t9;
    t135 = i_coriolis_current_tmp_tmp * t43;
    j_coriolis_current_tmp_tmp = t107 * t6 * t8;
    t130 = j_coriolis_current_tmp_tmp * t43;
    l_coriolis_current_tmp_tmp = t15 * t6 * t7;
    ct_idx_193 = l_coriolis_current_tmp_tmp * t43;
    ct_idx_194 = d317 * t44;
    ct_idx_195 = d322 * t34;
    ct_idx_196 = d324 * t34;
    t280 = d326 * t34;
    t281 = d336 * t33;
    t279 = d254 * t11 * t43;
    t264 = d255 * t11 * t43;
    t260 = d318 * t44;
    t215 = d256 * t11 * t43;
    t216 = d319 * t44;
    t217 = d320 * t44;
    t218 = d338 * t33;
    m_coriolis_current_tmp_tmp = d130 * t7 * t8 * t9;
    t219 = m_coriolis_current_tmp_tmp * t43;
    t220 = d322 * t44;
    t222 = d324 * t44;
    t209 = d326 * t44;
    t210 = d257 * t11 * t43;
    t211 = d339 * t34;
    t208 = d340 * t34;
    t207 = d341 * t34;
    t206 = d339 * t44;
    t184 = d340 * t44;
    t187 = d341 * t44;
    t190 = d342 * t34;
    t193 = d330 * t34 * t43;
    t194 = d332 * t34 * t43;
    t195 = d334 * t34 * t43;
    t196 = d342 * t44;
    t197 = d330 * t43 * t44;
    t204 = d332 * t43 * t44;
    t183 = d334 * t43 * t44;
    t178 = d337 * t34 * t43;
    t179 = d337 * t43 * t44;
    t180 = e_coriolis_current_tmp * t9;
    t163 = b_coriolis_current_tmp * t9;
    t170 = c_coriolis_current_tmp * t8;
    t171 = d_coriolis_current_tmp * t7;
    t115 = d3 * t8 * t9;
    coriolis_current[1] =
      (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
      ((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((t26 * t3 * -0.0010534045928040131 - d72 *
      0.011522913548876161) - d23 * 0.0030023202808742229) - t26 * t8 * 0.16306416209891961) + (((d73 *
      0.00034056475132481358 + d74 * 0.0039910806244350967) + d48 * 0.01766701891594424) + d51 * 0.12984476359341221)) +
      (((t26 * t46 * -0.0123514505447803 - t27 * t46 * 0.0123514505447803) + d75 * 0.00082698964793341513) + d76 *
      0.00082698964793341513)) + (((t26 * t58 * 0.00036505252473182878 + t27 * t58 * 0.00036505252473182878) + t26 * t70
      * 0.00088645303934360286) + t27 * t70 * 0.00088645303934360286)) + (((t28 * t70 * 0.00088645303934360286 + d77 *
      0.0010534045928040131) + d78 * 0.16306416209891961) - d79 * 0.00082698964793341513)) + (((d80 *
      -0.00082698964793341513 + d81 * 0.0123514505447803) - d82 * 0.00036505252473182878) - d83 * 0.0142272363015332)) +
      (((d84 * 0.071059551752123654 - t144 * t26 * 0.00088645303934360286) - t144 * t27 * 0.00088645303934360286) - t144
      * t28 * 0.00088645303934360286)) + (((d85 * -0.00088645303934360286 + d86 * 0.011522913548876161) - d87 *
      0.00034056475132481358) - d88 * 0.00082698964793341513)) + (((d89 * 0.001476372613115005 - d90 *
      0.0145172866714301) + d91 * 0.00088645303934360286) - d92 * 0.0015412172703065611)) + (((d93 *
      0.0019955403122175479 + d94 * 0.00082698964793341513) - d95 * 0.001133620832763626) - d96 * 0.00030813337424454951))
      + (((d97 * -0.0015412172703065611 + d98 * 0.001133620832763626) - d101 * 0.0019955403122175479) - d102 *
      0.00030813337424454951)) + (((d162 * -0.0021068091856080262 - d199 * 0.023045827097752311) - d200 *
      0.023045827097752311) - d68 * 0.32612832419783933)) + (((d222 * -0.00032581680446722681 + d100 *
      0.00040886121775334211) - d223 * 0.00032581680446722681) + d105 * 0.00068112950264962726)) + (((d104 *
      0.00040886121775334211 - d224 * 0.00032581680446722681) + d106 * 0.00068112950264962726) + d108 *
      0.00040886121775334211)) + (((d27 * 8.9904945245010626E-5 - d30 * 0.0001128199800959624) + d28 *
      8.9904945245010626E-5) - d31 * 0.0001128199800959624)) + (((d29 * 8.9904945245010626E-5 - d34 *
      0.0001128199800959624) + d24 * 0.002271775539606237) + d109 * 0.009068966662109006)) + (((d110 *
      0.009068966662109006 + d112 * 0.00073449743288493262) + d113 * 0.009068966662109006) + d114 *
      0.00073449743288493262)) + (((d115 * 0.00073449743288493262 + d35 * 0.0036009547637595139) + d2 * t45 *
      0.0017729060786872059) - d10 * t46 * 0.024702901089560612)) + (((d38 * 0.0036009547637595139 - d11 * t46 *
      0.024702901089560612) - d116 * 0.00168302364808843) + d39 * 0.0036009547637595139)) + (((d117 *
      0.00165397929586683 - d12 * t46 * 0.024702901089560612) - d118 * 0.00168302364808843) + d119 * 0.00165397929586683))
      + (((d120 * 0.00165397929586683 - d123 * 0.00168302364808843) + d121 * 0.00165397929586683) + d122 *
      0.00165397929586683)) + (((d10 * t58 * 0.00073010504946365755 + d11 * t58 * 0.00073010504946365755) + d12 * t58 *
      0.00073010504946365755) + d124 * 0.00165397929586683)) + (((d10 * t70 * 0.0017729060786872059 + d11 * t70 *
      0.0017729060786872059) + d14 * t70 * 0.0017729060786872059) + d12 * t70 * 0.0017729060786872059)) + (((d15 * t70 *
      0.0017729060786872059 + d16 * t70 * 0.0017729060786872059) - d125 * 0.020162882905592958) + d126 *
      0.0030824345406131231)) + (((d127 * -0.0039910806244350967 - d2 * t111 * 0.0017729060786872059) - d128 *
      0.00165397929586683) + d129 * 0.00165397929586683)) + (((d131 * -0.00165397929586683 + d132 * 0.00165397929586683)
      + d133 * 0.00165397929586683) - d134 * 0.00165397929586683)) + (((d10 * t144 * -0.0017729060786872059 - d11 * t144
      * 0.0017729060786872059) + d14 * t144 * 0.0017729060786872059) - d12 * t144 * 0.0017729060786872059)) + (((d15 *
      t144 * 0.0017729060786872059 + d16 * t144 * 0.0017729060786872059) + d135 * 0.004534483331054503) + d136 *
      0.001232533496978198)) + (((d137 * 0.0030824345406131231 - d138 * 0.004534483331054503) + d139 *
      0.0039910806244350967) + d140 * 0.001232533496978198)) + (((d42 * 0.000278685828102213 - d43 *
      0.00020443060887667111) - d141 * 0.000278685828102213) - d143 * 0.000278685828102213)) + (((d44 *
      0.001009961417751989 + d144 * 0.00020443060887667111) + d145 * 0.00020443060887667111) + d45 *
      5.640999004798118E-5)) + (((d46 * -4.4952472622505313E-5 - d147 * 0.00039579352520963638) - d148 *
      0.001009961417751989) - d149 * 0.00039579352520963638)) + (((d150 * -0.001009961417751989 - d151 *
      5.640999004798118E-5) - d152 * 0.00409235398772912) - d20 * 5.640999004798118E-5)) + (((d21 * 0.00409235398772912
      - d47 * 0.00016290840223361341) - d153 * 0.0028932351906267141) + d22 * 0.0028932351906267141)) + (((d154 *
      0.00073449743288493262 - d155 * 0.00168302364808843) - d210 * 0.000557371656204426) - d211 * 0.000557371656204426))
      + (((d3 * -0.00084850487367370275 - d65 * 0.00079158705041927288) - d156 * 0.0020199228355039789) - d66 *
      0.00079158705041927288)) + (((d67 * -0.00079158705041927288 - d157 * 0.0020199228355039789) - d69 *
      0.00079158705041927288) - d158 * 0.0020199228355039789)) + (((d70 * -0.00079158705041927288 - d159 *
      0.0020199228355039789) - d160 * 0.0020199228355039789) - d161 * 0.0001128199800959624)) + (((d164 *
      0.000557371656204426 + d165 * 0.000557371656204426) + d166 * 0.000557371656204426) - d167 * 0.00040886121775334211))
      + ((((d168 * -0.0061122871857206551 - d169 * 0.0061122871857206551) - d172 * 0.0061122871857206551) + d222 *
      ct_idx_286 * 0.00065163360893445374) + d173 * 0.00827461292070325)) + (((d223 * ct_idx_286 *
      0.00065163360893445374 + d174 * 0.00827461292070325) + d224 * ct_idx_286 * 0.00065163360893445374) + d175 *
      0.00827461292070325)) + (((d176 * -0.0033660472961768591 - d27 * ct_idx_286 * 0.0001798098904900212) + d179 *
      0.0041373064603516252) - d28 * ct_idx_286 * 0.0001798098904900212)) + ((((d180 * 0.0041373064603516252 - d29 *
      ct_idx_286 * 0.0001798098904900212) + d181 * 0.0041373064603516252) + d184 * 0.003056143592860328) + d185 *
      0.003056143592860328)) + (((d189 * 0.003056143592860328 - d190 * 0.001468994865769865) - d196 *
      0.00073449743288493262) - d201 * 0.00073449743288493262)) + (((d203 * -0.00073449743288493262 + d204 *
      0.00168302364808843) + d195 * 0.00168302364808843) + d262 * 0.00168302364808843)) + (((d197 * 0.00168302364808843
      + d205 * 0.00168302364808843) + d202 * 0.00168302364808843) + d263 * 0.00073449743288493262)) + (((d264 *
      0.00073449743288493262 + d265 * 0.00073449743288493262) - d231 * 0.0002987242947484708) - t13 *
      0.0001128199800959624)) + ((d206 * t26 * -0.0002987242947484708 - d206 * t27 * 0.0002987242947484708) - t137 *
      0.0001128199800959624)) + ((d206 * t29 * -0.0002987242947484708 - d232 * 0.0010825811068170821) - t71 * t26 *
      0.00042425243683685138)) + (((t72 * t26 * -0.00042425243683685138 - t109 * 0.0001128199800959624) - t51 *
      0.00040886121775334211) - d208 * t26 * 0.0010825811068170821)) + (((t71 * t27 * -0.00042425243683685138 - t72 *
      t27 * 0.00042425243683685138) + d234 * 0.001009961417751989) - d208 * t27 * 0.0010825811068170821)) + (((t71 * t28
      * -0.00042425243683685138 - t72 * t28 * 0.00042425243683685138) - t122 * 0.00040886121775334211) - d208 * t29 *
      0.0010825811068170821)) + (((d268 * -0.001009961417751989 + d235 * 0.0002987242947484708) - t118 *
      0.00040886121775334211) - d269 * 0.001009961417751989)) + (((d270 * -0.001009961417751989 - d236 *
      0.000278685828102213) + t48 * t26 * 0.0002987242947484708) + t48 * t27 * 0.0002987242947484708)) + (((d271 *
      0.000278685828102213 + t48 * t29 * 0.0002987242947484708) + d237 * 0.0010825811068170821) + d272 *
      0.000278685828102213)) + (((d273 * 0.000278685828102213 + t61 * t26 * 0.0010825811068170821) + t61 * t27 *
      0.0010825811068170821) + t61 * t29 * 0.0010825811068170821)) + (((t104 * -0.000557371656204426 - d42 * ct_idx_284 *
      0.000557371656204426) + t243 * 0.00040886121775334211) + t116 * 0.00040886121775334211)) + (((d43 * ct_idx_285 *
      0.00040886121775334211 - t55 * 0.0020199228355039789) - d44 * ct_idx_284 * 0.0020199228355039789) - t76 *
      0.0001128199800959624)) + (((t152 * 8.9904945245010626E-5 - t153 * 0.0001128199800959624) + t140 *
      8.9904945245010626E-5) - d45 * ct_idx_285 * 0.0001128199800959624)) + (((d46 * ct_idx_285 * 8.9904945245010626E-5
      + t50 * 0.00032581680446722681) + t90 * 0.00032581680446722681) + d47 * ct_idx_285 * 0.00032581680446722681)) +
      (((d242 * 0.00028397194245077958 + d243 * 0.00028397194245077958) + d244 * 0.00028397194245077958) - d245 *
      0.00028397194245077958)) + (((d163 * t6 * -0.00059744858949694148 - d171 * t6 * 0.00059744858949694148) + d254 *
      0.001135887769803119) + d255 * 0.001135887769803119)) + (((d256 * 0.001135887769803119 - d178 * t6 *
      0.00059744858949694148) - d249 * 0.00079158705041927288) - d250 * 0.00079158705041927288)) + ((t22 *
      -0.00084850487367370275 - t244 * 0.00084850487367370275) - d163 * t11 * 0.0021651622136341642)) + ((t99 *
      -0.00084850487367370275 - t172 * 0.00084850487367370275) - d212 * 0.000557371656204426)) + ((t110 *
      -0.0021651622136341642 - d171 * t11 * 0.0021651622136341642) - d99 * 0.00084850487367370275)) + ((t199 *
      -0.00084850487367370275 - t23 * 0.00084850487367370275) - d213 * 0.000557371656204426)) + ((d178 * t11 *
      -0.0021651622136341642 - d103 * 0.00084850487367370275) - d214 * 0.000557371656204426)) + (((d215 *
      -0.0020199228355039789 - d32 * t6 * t9 * 0.0021651622136341642) - d182 * t6 * t8 * 0.0021651622136341642) - d107 *
      0.00084850487367370275)) + (((d55 * -0.0020199228355039789 - d216 * 0.0020199228355039789) - d36 * t6 * t9 *
      0.0021651622136341642) - d186 * t6 * t8 * 0.0021651622136341642)) + (((d282 * t8 * t9 * 0.00059744858949694148 -
      d183 * 0.0020199228355039789) - d59 * 0.0020199228355039789) - d40 * t6 * t9 * 0.0021651622136341642)) + ((d191 *
      t6 * t8 * -0.0021651622136341642 + d3 * t11 * 0.00059744858949694148) + d283 * t8 * t9 * 0.00059744858949694148))
      + (((d251 * t10 * -8.9904945245010626E-5 - d187 * 0.0020199228355039789) - d61 * 0.0020199228355039789) - d257 *
      0.001135887769803119)) + ((d5 * t10 * 0.00059744858949694148 + d284 * t8 * t9 * 0.00059744858949694148) - d252 *
      t10 * 8.9904945245010626E-5)) + ((d192 * -0.0020199228355039789 + d274 * 0.000557371656204426) + d32 * t9 * t11 *
      0.00059744858949694148)) + ((d182 * t8 * t11 * 0.00059744858949694148 - d253 * t10 * 8.9904945245010626E-5) + d275
      * 0.000557371656204426)) + ((d276 * 0.000557371656204426 + d36 * t9 * t11 * 0.00059744858949694148) + d186 * t8 *
      t11 * 0.00059744858949694148)) + ((d68 * t9 * t11 * 0.0021651622136341642 + d277 * 0.000557371656204426) + d40 *
      t9 * t11 * 0.00059744858949694148)) + (((d191 * t8 * t11 * 0.00059744858949694148 + d11 * t8 * t9 * t11 *
      0.0021651622136341642) + t155 * 0.00084850487367370275) - d225 * t10 * t11 * 0.00032581680446722681)) + (((d278 *
      0.000557371656204426 + t201 * t10 * t11 * 0.0021651622136341642) + d12 * t8 * t9 * t11 * 0.0021651622136341642) +
      t200 * 0.00084850487367370275)) + (((d226 * t10 * t11 * -0.00032581680446722681 + t223 * 0.00084850487367370275) -
      d227 * t10 * t11 * 0.00032581680446722681) + d71 * 0.000557371656204426)) + (((d279 * 0.0020199228355039789 - d258
      * 0.0010825811068170821) - d259 * 0.0010825811068170821) + t75 * 0.000557371656204426)) + (((t52 * t26 *
      -0.0010825811068170821 - t54 * t26 * 0.0010825811068170821) - t52 * t27 * 0.0010825811068170821) + t74 *
      0.000557371656204426)) + (((t54 * t27 * -0.0010825811068170821 - t52 * t28 * 0.0010825811068170821) - t54 * t28 *
      0.0010825811068170821) - t52 * t29 * 0.0010825811068170821)) + (((d260 * 0.0002987242947484708 - t54 * t29 *
      0.0010825811068170821) + d261 * 0.0002987242947484708) + t117 * 0.0020199228355039789)) + ((t120 * t26 *
      0.0002987242947484708 + t121 * t26 * 0.0002987242947484708) + t120 * t27 * 0.0002987242947484708)) + ((t124 *
      0.0020199228355039789 + t121 * t27 * 0.0002987242947484708) + t120 * t28 * 0.0002987242947484708)) + ((t121 * t28 *
      0.0002987242947484708 + t120 * t29 * 0.0002987242947484708) + t121 * t29 * 0.0002987242947484708)) + ((d280 *
      0.00042425243683685138 + d281 * 0.00042425243683685138) + d231 * ct_idx_283 * 0.00059744858949694148)) + ((t20 *
      0.00022563996019192469 + t13 * ct_idx_285 * 0.00022563996019192469) + d285 * 0.00042425243683685138)) + (((t21 *
      0.00022563996019192469 + d232 * ct_idx_283 * 0.0021651622136341642) + t137 * ct_idx_285 * 0.00022563996019192469)
      + t17 * 0.00022563996019192469)) + (((t109 * ct_idx_284 * 0.00022563996019192469 - t18 * 0.0020199228355039789) +
      t56 * 0.00081772243550668432) - d234 * ct_idx_284 * 0.0020199228355039789)) + (((t51 * ct_idx_285 *
      0.00081772243550668432 + ct_idx_228 * 0.00081772243550668432) - d235 * ct_idx_283 * 0.00059744858949694148) + t122
      * ct_idx_285 * 0.00081772243550668432)) + (((ct_idx_236 * 0.00081772243550668432 + t118 * ct_idx_284 *
      0.00081772243550668432) + ct_idx_224 * 0.000557371656204426) + d236 * ct_idx_284 * 0.000557371656204426)) +
      (((d286 * -0.00042425243683685138 - d237 * ct_idx_283 * 0.0021651622136341642) + d287 * 0.00039579352520963638) +
      d288 * 0.00039579352520963638)) + (((d289 * 0.00039579352520963638 + t104 * ct_idx_284 * 0.0011147433124088519) -
      ct_idx_226 * 0.00081772243550668432) - t243 * ct_idx_285 * 0.00081772243550668432)) + (((t116 * ct_idx_285 *
      -0.00081772243550668432 + t55 * ct_idx_284 * 0.0040398456710079578) + ct_idx_219 * 0.00022563996019192469) -
      ct_idx_222 * 0.0001798098904900212)) + (((t76 * ct_idx_285 * 0.00022563996019192469 - t152 * ct_idx_285 *
      0.0001798098904900212) + t153 * ct_idx_285 * 0.00022563996019192469) - t140 * ct_idx_285 * 0.0001798098904900212))
      + (((ct_idx_218 * -0.00065163360893445374 - t50 * ct_idx_285 * 0.00065163360893445374) - t90 * ct_idx_285 *
      0.00065163360893445374) - d7 * 0.00039579352520963638)) + ((d299 * 8.0114259738899468E-5 - d303 *
      8.0114259738899468E-5) - d304 * 8.0114259738899468E-5)) + (((d305 * -8.0114259738899468E-5 - d309 *
      0.00028397194245077958) - d310 * 0.00028397194245077958) - d311 * 0.00028397194245077958)) + (((d343 *
      -0.0012622677360663219 - d239 * 0.0012622677360663219) - d241 * 0.0012622677360663219) - d344 *
      0.00055087307466369949)) + (((d345 * -0.00055087307466369949 - d346 * 0.00055087307466369949) + d313 *
      0.00028397194245077958) + d348 * 0.0012622677360663219)) + (((d349 * 0.00055087307466369949 - d315 *
      0.00016022851947779891) - d317 * 0.002271775539606237) - d33 * t6 * 0.00059744858949694148)) + ((d246 *
      -0.0020199228355039789 - d247 * 0.0020199228355039789) - d327 * 0.0040474015151066153)) + ((d328 *
      -0.0040474015151066153 - d329 * 0.0040474015151066153) - d37 * t6 * 0.00059744858949694148)) + ((t133 * t6 * t9 *
      -0.0021651622136341642 - d377 * t8 * 0.0021651622136341642) - d41 * t6 * 0.00059744858949694148)) + ((d170 * t6 *
      t9 * -0.0021651622136341642 - t131 * t6 * t8 * 0.0021651622136341642) + d318 * 0.00016022851947779891)) + ((d319 *
      0.00016022851947779891 + d320 * 0.00016022851947779891) - d217 * t10 * 0.0021651622136341642)) + ((d177 * t6 * t9 *
      -0.0021651622136341642 - t154 * t6 * t8 * 0.0021651622136341642) - d33 * t11 * 0.0021651622136341642)) + ((d218 *
      t10 * -0.0021651622136341642 + d350 * 0.000557371656204426) + d351 * 0.000557371656204426)) + ((d331 *
      -0.0027303267883931012 - d333 * 0.0027303267883931012) - d335 * 0.0027303267883931012)) + ((d37 * t11 *
      -0.0021651622136341642 - d219 * t10 * 0.0021651622136341642) + d352 * 0.000557371656204426)) + ((d353 *
      0.000557371656204426 + t22 * t11 * 0.00059744858949694148) + t244 * t11 * 0.00059744858949694148)) + ((d41 * t11 *
      -0.0021651622136341642 + t99 * t11 * 0.00059744858949694148) + t172 * t11 * 0.00059744858949694148)) + (((d99 *
      t11 * 0.00059744858949694148 + t199 * t11 * 0.00059744858949694148) + t23 * t11 * 0.00059744858949694148) + d322 *
      0.002271775539606237)) + (((d324 * 0.002271775539606237 + d326 * 0.002271775539606237) + d251 * t8 * t9 *
      0.00059744858949694148) + d103 * t11 * 0.00059744858949694148)) + ((d336 * 0.0040474015151066153 + d252 * t8 * t9 *
      0.00059744858949694148) + d107 * t11 * 0.00059744858949694148)) + ((d295 * 0.0020199228355039789 + d296 *
      0.0020199228355039789) + d253 * t8 * t9 * 0.00059744858949694148)) + ((d111 * t6 * t9 * t10 *
      0.00059744858949694148 + d142 * t6 * t8 * t10 * 0.00059744858949694148) + d222 * t8 * t9 * t10 *
      0.0021651622136341642)) + (((d225 * t8 * t9 * t11 * 0.0021651622136341642 + d223 * t8 * t9 * t10 *
      0.0021651622136341642) + d338 * 0.0027303267883931012) + d226 * t8 * t9 * t11 * 0.0021651622136341642)) + (((d224 *
      t8 * t9 * t10 * 0.0021651622136341642 + d227 * t8 * t9 * t11 * 0.0021651622136341642) + d111 * t9 * t10 * t11 *
      0.0021651622136341642) + d142 * t8 * t10 * t11 * 0.0021651622136341642)) + ((t155 * t11 * -0.00059744858949694148
      - t200 * t11 * 0.00059744858949694148) - t223 * t11 * 0.00059744858949694148)) + (((d339 * 0.001135887769803119 +
      d340 * 0.001135887769803119) + d341 * 0.001135887769803119) + d354 * 0.00168302364808843)) + (((d355 *
      0.00168302364808843 + d356 * 0.00168302364808843) - d342 * 0.001135887769803119) + d357 * 0.00073449743288493262))
      + (((d358 * 0.00073449743288493262 + d359 * 0.00073449743288493262) - d360 * 0.00168302364808843) - d361 *
      0.00073449743288493262)) + ((ct_idx_210 * -0.0020199228355039789 - ct_idx_207 * 0.0020199228355039789) -
      ct_idx_211 * t9 * ct_idx_199 * 0.00059744858949694148)) + ((ct_idx_215 * t8 * ct_idx_199 * -0.00059744858949694148
      + ct_idx_208 * 0.000557371656204426) + ct_idx_209 * 0.00032581680446722681)) + ((ct_idx_202 * 0.000557371656204426
      - d25 * t9 * t11 * ct_idx_199 * 0.0021651622136341642) - d52 * t8 * t11 * ct_idx_199 * 0.0021651622136341642)) +
      (((d228 * 0.00032581680446722681 + ct_idx_204 * 0.00032581680446722681) - ct_idx_198 * 8.9904945245010626E-5) -
      d209 * 8.9904945245010626E-5)) + ((ct_idx_200 * -8.9904945245010626E-5 + d258 * ct_idx_283 * 0.0021651622136341642)
      + d259 * ct_idx_283 * 0.0021651622136341642)) + ((t75 * ct_idx_284 * -0.0011147433124088519 - t74 * ct_idx_283 *
      0.0011147433124088519) - d260 * ct_idx_283 * 0.00059744858949694148)) + ((d261 * ct_idx_283 *
      -0.00059744858949694148 - t117 * ct_idx_284 * 0.0040398456710079578) - t124 * ct_idx_283 * 0.0040398456710079578))
      + ((t20 * ct_idx_285 * -0.00045127992038384939 - t21 * ct_idx_285 * 0.00045127992038384939) - t17 * ct_idx_284 *
      0.00045127992038384939)) + (((t18 * ct_idx_284 * 0.0040398456710079578 - t56 * ct_idx_285 * 0.0016354448710133691)
      - ct_idx_228 * ct_idx_285 * 0.0016354448710133691) - ct_idx_236 * ct_idx_284 * 0.0016354448710133691)) +
      (((ct_idx_224 * ct_idx_284 * -0.0011147433124088519 - d363 * 0.0041373064603516252) - d365 * 0.003056143592860328)
      + ct_idx_226 * ct_idx_285 * 0.0016354448710133691)) + (((ct_idx_219 * ct_idx_285 * -0.00045127992038384939 +
      ct_idx_222 * ct_idx_285 * 0.0003596197809800425) + d366 * 0.0041373064603516252) + d368 * 0.0041373064603516252))
      + (((d369 * 0.0041373064603516252 + ct_idx_218 * ct_idx_285 * 0.001303267217868907) + d370 *
      0.00073449743288493262) + d371 * 0.003056143592860328)) + (((d373 * 0.003056143592860328 + d374 *
      0.003056143592860328) - d375 * 0.00168302364808843) - d376 * 0.00073449743288493262)) + (((d383 *
      -0.00073449743288493262 - d302 * 0.00073449743288493262) - d384 * 0.001528071796430164) - d385 *
      0.001528071796430164)) + (((d393 * -0.001528071796430164 + d394 * 0.002068653230175813) + d395 *
      0.002068653230175813) + d398 * 0.002068653230175813)) + (((d399 * 0.00168302364808843 + d400 * 0.00168302364808843)
      + d401 * 0.00168302364808843) - d306 * 0.00042075591202210739)) + (((d307 * -0.00042075591202210739 - d308 *
      0.00042075591202210739) + d403 * 0.001528071796430164) - d405 * 0.002068653230175813)) + (((d406 *
      -0.00018362435822123321 - d407 * 0.00018362435822123321) - d408 * 0.00018362435822123321) + t102 *
      0.00042075591202210739)) + ((t92 * 0.00018362435822123321 - t81 * 0.00040886121775334211) + t82 *
      0.0001128199800959624)) + ((t83 * 0.00818470797545824 + t88 * 0.0001128199800959624) + t89 * 0.0057864703812534283))
      + (((t91 * 0.00040886121775334211 + t68 * 0.00040886121775334211) + t127 * 0.00040886121775334211) + t103 *
      0.00040886121775334211)) + ((t113 * -0.0001128199800959624 - t114 * 0.00818470797545824) - t94 *
      0.0001128199800959624)) + ((t96 * -0.00818470797545824 - t97 * 0.0001128199800959624) - t98 * 0.00818470797545824))
      + ((t128 * -0.0001128199800959624 - t151 * 0.0001128199800959624) - t148 * 0.0001128199800959624)) + ((t149 *
      -0.0057864703812534283 - t150 * 0.0057864703812534283) - t136 * 0.0057864703812534283)) + (((t146 *
      -0.00040886121775334211 - t253 * 0.00040886121775334211) - t247 * 0.00040886121775334211) - t185 *
      0.001468994865769865)) + (((t181 * 0.0033660472961768591 + t168 * 0.0041373064603516252) + t167 *
      0.0041373064603516252) + t165 * 0.0041373064603516252)) + (((t166 * 0.0033660472961768591 + t164 *
      0.001468994865769865) + t162 * 0.001468994865769865) + t139 * 0.001468994865769865)) + (((d327 * ct_idx_286 *
      -8.9904945245010626E-5 + t141 * 0.003056143592860328) - d328 * ct_idx_286 * 8.9904945245010626E-5) + t145 *
      0.003056143592860328)) + (((d329 * ct_idx_286 * -8.9904945245010626E-5 + t147 * 0.003056143592860328) + t135 *
      0.0061122871857206551) + t130 * 0.0061122871857206551)) + (((ct_idx_193 * 0.0061122871857206551 + ct_idx_194 *
      0.001468994865769865) - d331 * ct_idx_286 * 0.00032581680446722681) - d333 * ct_idx_286 * 0.00032581680446722681))
      + (((ct_idx_195 * -0.0033660472961768591 - d335 * ct_idx_286 * 0.00032581680446722681) - ct_idx_196 *
      0.0033660472961768591) - t280 * 0.0033660472961768591)) + (((t281 * -0.0041373064603516252 - t279 *
      0.00827461292070325) - t264 * 0.00827461292070325) - t260 * 0.0033660472961768591)) + (((t215 *
      -0.00827461292070325 - t216 * 0.0033660472961768591) - t217 * 0.0033660472961768591) + d336 * ct_idx_286 *
      8.9904945245010626E-5)) + (((t218 * -0.003056143592860328 - t219 * 0.0061122871857206551) - t220 *
      0.001468994865769865) - t222 * 0.001468994865769865)) + (((t209 * -0.001468994865769865 + d338 * ct_idx_286 *
      0.00032581680446722681) + t210 * 0.00827461292070325) + t211 * 0.00168302364808843)) + (((t208 *
      0.00168302364808843 + t207 * 0.00168302364808843) + t206 * 0.00073449743288493262) + t184 * 0.00073449743288493262))
      + (((t187 * 0.00073449743288493262 - t190 * 0.00168302364808843) + t193 * 0.00073449743288493262) + t194 *
      0.00073449743288493262)) + (((t195 * 0.00073449743288493262 - t196 * 0.00073449743288493262) - t197 *
      0.00168302364808843) - t204 * 0.00168302364808843)) + (((t183 * -0.00168302364808843 - t178 *
      0.00073449743288493262) + t179 * 0.00168302364808843) + t101 * ct_idx_199 * 0.0021651622136341642)) +
      ((e_coriolis_current_tmp * ct_idx_199 * -0.0011147433124088519 + i_coriolis_current_tmp * 0.00081772243550668432)
      - coriolis_current_tmp * t11 * ct_idx_199 * 0.00059744858949694148)) + ((j_coriolis_current_tmp *
      0.00081772243550668432 - g_coriolis_current_tmp * t11 * ct_idx_199 * 0.0040398456710079578) +
      k_coriolis_current_tmp * 0.00081772243550668432)) + ((l_coriolis_current_tmp * -0.00022563996019192469 +
      m_coriolis_current_tmp * 0.0001798098904900212) - ct_idx_214 * t8 * t9 * ct_idx_199 * 0.0021651622136341642)) +
                        ((n_coriolis_current_tmp * -0.00022563996019192469 + o_coriolis_current_tmp *
      0.0001798098904900212) - p_coriolis_current_tmp * 0.00022563996019192469)) + ((q_coriolis_current_tmp *
      0.0001798098904900212 + r_coriolis_current_tmp * 0.00065163360893445374) + ct_idx_225 * t8 * t9 * t11 * ct_idx_199
      * 0.00059744858949694148)) + (((s_coriolis_current_tmp * 0.00065163360893445374 + t_coriolis_current_tmp *
      0.00065163360893445374) + ct_idx_210 * ct_idx_284 * 0.0040398456710079578) + ct_idx_207 * ct_idx_283 *
      0.0040398456710079578)) + ((ct_idx_208 * ct_idx_284 * -0.0011147433124088519 - u_coriolis_current_tmp *
      0.00065163360893445374) - ct_idx_202 * ct_idx_283 * 0.0011147433124088519)) + ((ct_idx_209 * ct_idx_285 *
      -0.00065163360893445374 - v_coriolis_current_tmp * 0.00065163360893445374) - d228 * ct_idx_285 *
      0.00065163360893445374)) + ((w_coriolis_current_tmp * -0.00065163360893445374 - ct_idx_204 * ct_idx_284 *
      0.00065163360893445374) + x_coriolis_current_tmp * 0.0001798098904900212)) + ((ct_idx_198 * ct_idx_285 *
      0.0001798098904900212 + y_coriolis_current_tmp * 0.0001798098904900212) + d209 * ct_idx_285 *
      0.0001798098904900212)) + ((ab_coriolis_current_tmp * 0.0001798098904900212 + ct_idx_200 * ct_idx_284 *
      0.0001798098904900212) - b_coriolis_current_tmp * t6 * t9 * t10 * 0.00065163360893445374)) +
                ((c_coriolis_current_tmp * t6 * t8 * t10 * -0.00065163360893445374 - d_coriolis_current_tmp * t6 * t7 *
                  t10 * 0.00065163360893445374) + t163 * t10 * t11 * 0.0001798098904900212)) + ((t170 * t10 * t11 *
      0.0001798098904900212 + t171 * t10 * t11 * 0.0001798098904900212) + t110 * t8 * t9 * t10 * 0.00065163360893445374))
              + ((t115 * t10 * t11 * -0.0001798098904900212 + t180 * ct_idx_199 * 0.00045127992038384939) -
                 f_coriolis_current_tmp * t9 * ct_idx_199 * 0.0040398456710079578)) + ((g_coriolis_current_tmp * t9 *
               t11 * ct_idx_199 * 0.0016354448710133691 + h_coriolis_current_tmp * t9 * t11 * ct_idx_199 *
               0.0011147433124088519) - i_coriolis_current_tmp * ct_idx_285 * 0.0016354448710133691)) +
            ((j_coriolis_current_tmp * ct_idx_284 * -0.0016354448710133691 - k_coriolis_current_tmp * ct_idx_283 *
              0.0016354448710133691) + l_coriolis_current_tmp * ct_idx_285 * 0.00045127992038384939)) +
           ((m_coriolis_current_tmp * ct_idx_285 * -0.0003596197809800425 + n_coriolis_current_tmp * ct_idx_284 *
             0.00045127992038384939) - o_coriolis_current_tmp * ct_idx_284 * 0.0003596197809800425)) +
          ((p_coriolis_current_tmp * ct_idx_283 * 0.00045127992038384939 - q_coriolis_current_tmp * ct_idx_283 *
            0.0003596197809800425) - r_coriolis_current_tmp * ct_idx_285 * 0.001303267217868907)) +
         ((s_coriolis_current_tmp * ct_idx_284 * -0.001303267217868907 - t_coriolis_current_tmp * ct_idx_283 *
           0.001303267217868907) + u_coriolis_current_tmp * ct_idx_285 * 0.001303267217868907)) +
        ((v_coriolis_current_tmp * ct_idx_285 * 0.001303267217868907 + w_coriolis_current_tmp * ct_idx_284 *
          0.001303267217868907) - x_coriolis_current_tmp * ct_idx_285 * 0.0003596197809800425)) +
       ((y_coriolis_current_tmp * ct_idx_285 * -0.0003596197809800425 - ab_coriolis_current_tmp * ct_idx_284 *
         0.0003596197809800425) - t101 * t8 * t9 * t10 * ct_idx_199 * 0.001303267217868907)) + coriolis_current_tmp * t8
      * t9 * t10 * t11 * ct_idx_199 * 0.0003596197809800425;
    d2 = ct_idx_199 * t46;
    d3 = t25 * t46;
    d5 = ct_idx_199 * t58;
    d25 = t25 * t58;
    d26 = ct_idx_199 * t70;
    d27 = t25 * t70;
    d28 = t144 * ct_idx_199;
    d29 = t144 * t25;
    d32 = t6 * t9;
    d33 = d32 * ct_idx_199;
    d36 = t11 * t9;
    d37 = d36 * ct_idx_199;
    d40 = d206 * t25;
    d41 = d208 * t25;
    d49 = t48 * t25;
    d50 = t61 * t25;
    d51 = t52 * t25;
    d52 = t54 * t25;
    d53 = t120 * t25;
    d54 = t121 * t25;
    d60 = d231 * t30;
    d68 = d232 * t30;
    d99 = d235 * t30;
    d63 *= t9;
    d103 = d63 * ct_idx_199;
    d107 = d103 * t40;
    d111 = d64 * t8;
    d130 = d111 * ct_idx_199;
    d142 = d130 * t40;
    d162 = d237 * t30;
    d163 = t3 * t9;
    d170 = d163 * t11;
    d171 = d170 * ct_idx_199;
    d177 = d171 * t40;
    d178 = t4 * t8;
    d182 = d178 * t11;
    d186 = d182 * ct_idx_199;
    d191 = d186 * t40;
    d208 = d42 * t30;
    d209 = d208 * ct_idx_253;
    d217 = d44 * t30;
    d218 = d217 * ct_idx_253;
    d219 = d33 * t30;
    d222 = d219 * ct_idx_290;
    d223 = d33 * ct_idx_253 * t40;
    d224 = d42 * t40 * ct_idx_290;
    t61 = d37 * t30;
    t87 = t61 * ct_idx_290;
    t12 = d37 * ct_idx_253 * t40;
    d228 = d44 * t40 * ct_idx_290;
    coriolis_current_tmp = d229 * ct_idx_199;
    t104 = d207 * t11;
    b_coriolis_current_tmp = t104 * ct_idx_199;
    c_coriolis_current_tmp = d43 * t30;
    d_coriolis_current_tmp = d45 * t30;
    e_coriolis_current_tmp = d258 * t30;
    f_coriolis_current_tmp = d259 * t30;
    t243 = d58 * ct_idx_199;
    g_coriolis_current_tmp = t243 * t40;
    i_coriolis_current_tmp = d260 * t30;
    j_coriolis_current_tmp = d261 * t30;
    t117 = d57 * t11;
    t116 = t117 * ct_idx_199;
    k_coriolis_current_tmp = t116 * t40;
    t120 = d146 * t8 * t9;
    t121 = t120 * ct_idx_199;
    l_coriolis_current_tmp = t121 * t40;
    t14 = t283 * t11;
    t84 = t14 * ct_idx_199;
    m_coriolis_current_tmp = t84 * t40;
    t86 = d234 * t30;
    n_coriolis_current_tmp = t86 * ct_idx_253;
    t77 = coriolis_current_tmp * t30;
    o_coriolis_current_tmp = t77 * ct_idx_290;
    p_coriolis_current_tmp = coriolis_current_tmp * ct_idx_253 * t40;
    t105 = d236 * t30;
    q_coriolis_current_tmp = t105 * ct_idx_253;
    t106 = b_coriolis_current_tmp * t30;
    r_coriolis_current_tmp = t106 * ct_idx_290;
    s_coriolis_current_tmp = b_coriolis_current_tmp * ct_idx_253 * t40;
    t_coriolis_current_tmp = d234 * t40 * ct_idx_290;
    t107 = c_coriolis_current_tmp * ct_idx_253;
    u_coriolis_current_tmp = t107 * ct_idx_262;
    v_coriolis_current_tmp = d236 * t40 * ct_idx_290;
    t15 = d_coriolis_current_tmp * ct_idx_253;
    w_coriolis_current_tmp = t15 * ct_idx_262;
    x_coriolis_current_tmp = c_coriolis_current_tmp * ct_idx_290 * ct_idx_291;
    t52 = d43 * ct_idx_253;
    y_coriolis_current_tmp = t52 * t40 * ct_idx_291;
    ab_coriolis_current_tmp = d43 * ct_idx_262 * t40 * ct_idx_290;
    t101 = d_coriolis_current_tmp * ct_idx_290 * ct_idx_291;
    t54 = d45 * ct_idx_253;
    t19 = t54 * t40 * ct_idx_291;
    t16 = d45 * ct_idx_262 * t40 * ct_idx_290;
    coriolis_current[2] =
      (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((ct_idx_199
      * t3 * -0.00054422507411123642 - t25 * t3 * 0.0010884501482224731) - d72 * 0.014473223347714311) + ct_idx_199 * t8
      * 0.102753601582932) + (((d23 * 0.00036032901905367259 + t25 * t8 * 0.2055072031658641) + d73 *
      0.0002341155938542742) + d74 * 0.00026810979222200132)) + (((d2 * 0.0077569488673412844 + d3 * 0.01551389773468257)
      + d75 * 0.0010993626142855139) + d76 * 0.0010993626142855139)) + (((d5 * -0.0001254746539140254 - d25 *
      0.00025094930782805069) - d26 * 0.00058920527796775209) - d27 * 0.001178410555935504)) + (((d77 *
      -0.00054422507411123642 + d78 * 0.102753601582932) - d79 * 0.0010993626142855139) - d80 * 0.0010993626142855139))
      + (((d81 * 0.0077569488673412844 - d82 * 0.0001254746539140254) - d83 * 0.0051860151292104136) + d84 *
      0.081266055095584114)) + (((d28 * 0.00058920527796775209 + d29 * 0.001178410555935504) - d85 *
      0.00058920527796775209) + d86 * 0.014473223347714311)) + (((d87 * -0.0002341155938542742 - d88 *
      0.0010993626142855139) - d89 * 0.00759684566786825) - d90 * 0.001253060768110761)) + (((d91 *
      0.00058920527796775209 + d92 * 0.00010966245361946109) + d93 * 0.00013405489611100071) + d94 *
      0.0010993626142855139)) + (((d95 * -0.00049425149917474746 - d96 * 0.00057629983145170377) + d97 *
      0.00010966245361946109) + d98 * 0.00049425149917474746)) + (((d101 * -0.00013405489611100071 - d102 *
      0.00057629983145170377) - d199 * 0.028946446695428611) - d200 * 0.028946446695428611)) + (((d100 *
      7.91832273806773E-5 + d105 * 0.0004682311877085483) + d104 * 7.91832273806773E-5) + d106 * 0.0004682311877085483))
      + (((d108 * 7.91832273806773E-5 - d30 * 0.000100787784430004) - d31 * 0.000100787784430004) - d34 *
      0.000100787784430004)) + (((d24 * -0.0031245499141437328 + d109 * 0.00395401199339798) + d110 *
      0.00395401199339798) - d112 * 0.0004090806016031226)) + (((d113 * 0.00395401199339798 - d114 *
      0.0004090806016031226) - d115 * 0.0004090806016031226) + d35 * 0.0030481236945417629)) + (((d38 *
      0.0030481236945417629 + d116 * 0.0003225898615597983) + d39 * 0.0030481236945417629) + d117 * 0.002198725228571027))
      + (((d118 * 0.0003225898615597983 + d119 * 0.002198725228571027) + d120 * 0.002198725228571027) + d123 *
      0.0003225898615597983)) + (((d121 * 0.002198725228571027 + d122 * 0.002198725228571027) + d124 *
      0.002198725228571027) - d125 * 3.7825381111140779E-5)) + (((d126 * -0.00021932490723892211 - d127 *
      0.00026810979222200132) - d128 * 0.002198725228571027) + d129 * 0.002198725228571027)) + (((d131 *
      -0.002198725228571027 + d132 * 0.002198725228571027) + d133 * 0.002198725228571027) - d134 * 0.002198725228571027))
      + (((d135 * 0.00197700599669899 + d136 * 0.0023051993258068151) - d137 * 0.00021932490723892211) - d138 *
      0.00197700599669899)) + (((d139 * 0.00026810979222200132 + d140 * 0.0023051993258068151) - d141 *
      0.00024896412091698482) - d143 * 0.00024896412091698482)) + (((d144 * 3.9591613690338653E-5 + d145 *
      3.9591613690338653E-5) - d147 * 0.0006966114979542903) - d148 * 0.0001955969436940153)) + (((d149 *
      -0.0006966114979542903 - d150 * 0.0001955969436940153) - d151 * 5.039389221500199E-5) + d152 *
      0.0001446502557068039)) + (((d20 * -5.039389221500199E-5 - d21 * 0.0001446502557068039) - d153 *
      0.001410643421579826) + d22 * 0.001410643421579826)) + (((d154 * -0.0004090806016031226 + d155 *
      0.0003225898615597983) - d210 * 0.00049792824183396965) - d211 * 0.00049792824183396965)) + (((d65 *
      -0.001393222995908581 - d156 * 0.00039119388738803059) - d66 * 0.001393222995908581) - d67 * 0.001393222995908581))
      + (((d157 * -0.00039119388738803059 - d69 * 0.001393222995908581) - d158 * 0.00039119388738803059) - d70 *
      0.001393222995908581)) + (((d159 * -0.00039119388738803059 - d160 * 0.00039119388738803059) - d161 *
      0.000100787784430004) + d164 * 0.00049792824183396965)) + (((d165 * 0.00049792824183396965 + d166 *
      0.00049792824183396965) - d167 * 7.91832273806773E-5) - d168 * 0.0028212868431596529)) + (((d169 *
      -0.0028212868431596529 - d172 * 0.0028212868431596529) - d173 * 0.00028930051141360779) - d174 *
      0.00028930051141360779)) + (((d175 * -0.00028930051141360779 + d176 * 0.0006451797231195966) - d179 *
      0.0001446502557068039) - d180 * 0.0001446502557068039)) + ((d181 * -0.0001446502557068039 + d184 *
      0.001410643421579826) + d185 * 0.001410643421579826)) + (((d189 * 0.001410643421579826 + d190 *
      0.00081816120320624521) + d196 * 0.0004090806016031226) + d201 * 0.0004090806016031226)) + (((d203 *
      0.0004090806016031226 - d204 * 0.0003225898615597983) - d195 * 0.0003225898615597983) - d262 *
      0.0003225898615597983)) + (((d197 * -0.0003225898615597983 - d205 * 0.0003225898615597983) - d202 *
      0.0003225898615597983) - d263 * 0.0004090806016031226)) + (((d264 * -0.0004090806016031226 - d265 *
      0.0004090806016031226) + d231 * 0.00013343274745087171) + d40 * 0.00026686549490174347)) + (((d266 *
      0.0003733501266590217 + d267 * 0.0003733501266590217) + d232 * 0.0001048305173209615) + t71 * t25 *
      0.00074670025331804351)) + (((t72 * t25 * 0.00074670025331804351 + d41 * 0.000209661034641923) - d268 *
      0.0001955969436940153) - d235 * 0.00013343274745087171)) + (((d269 * -0.0001955969436940153 - d49 *
      0.00026686549490174347) - d270 * 0.0001955969436940153) + d271 * 0.00024896412091698482)) + (((d237 *
      -0.0001048305173209615 + d272 * 0.00024896412091698482) - d50 * 0.000209661034641923) + d273 *
      0.00024896412091698482)) + (((d242 * -0.00039056873926796671 - d243 * 0.00039056873926796671) - d244 *
      0.00039056873926796671) + d245 * 0.00039056873926796671)) + (((d254 * -0.0015622749570718671 - d255 *
      0.0015622749570718671) - d256 * 0.0015622749570718671) - d249 * 0.001393222995908581)) + (((d250 *
      -0.001393222995908581 - d212 * 0.00049792824183396965) - d213 * 0.00049792824183396965) - d214 *
      0.00049792824183396965)) + (((d215 * -0.00039119388738803059 - d55 * 0.00039119388738803059) - d216 *
      0.00039119388738803059) - d183 * 0.00039119388738803059)) + (((d59 * -0.00039119388738803059 - d187 *
      0.00039119388738803059) - d61 * 0.00039119388738803059) + d257 * 0.0015622749570718671)) + (((d192 *
      -0.00039119388738803059 + d274 * 0.00049792824183396965) + d275 * 0.00049792824183396965) + d276 *
      0.00049792824183396965)) + (((d277 * 0.00049792824183396965 + d278 * 0.00049792824183396965) + d71 *
      0.00049792824183396965) + d279 * 0.00039119388738803059)) + ((d258 * 0.0001048305173209615 + d259 *
      0.0001048305173209615) + d51 * 0.000209661034641923)) + ((d52 * 0.000209661034641923 - d260 *
      0.00013343274745087171) - d261 * 0.00013343274745087171)) + ((d53 * -0.00026686549490174347 - d54 *
      0.00026686549490174347) + d60 * 0.00013343274745087171)) + (((d280 * 0.0003733501266590217 + d281 *
      0.0003733501266590217) + d68 * 0.0001048305173209615) + d285 * 0.0003733501266590217)) + ((d99 *
      -0.00013343274745087171 - d107 * 0.00013343274745087171) - d142 * 0.00013343274745087171)) + ((d162 *
      -0.0001048305173209615 - d286 * 0.0003733501266590217) - d177 * 0.0001048305173209615)) + (((d191 *
      -0.0001048305173209615 + d209 * 0.00024896412091698482) + d287 * 0.0006966114979542903) + d218 *
      0.0001955969436940153)) + (((d288 * 0.0006966114979542903 + d289 * 0.0006966114979542903) - d222 *
      0.00024896412091698482) - d223 * 0.00024896412091698482)) + (((d224 * -0.00024896412091698482 - t87 *
      0.0001955969436940153) - t12 * 0.0001955969436940153) - d7 * 0.0006966114979542903)) + (((d228 *
      -0.0001955969436940153 + d299 * 0.00014100411181475051) - d381 * 5.039389221500199E-5) - d382 *
      5.039389221500199E-5)) + ((d389 * -5.039389221500199E-5 - d391 * 3.9591613690338653E-5) - d392 *
      3.9591613690338653E-5)) + (((d397 * -3.9591613690338653E-5 - d303 * 0.00014100411181475051) - d304 *
      0.00014100411181475051) - d305 * 0.00014100411181475051)) + (((d402 * 5.039389221500199E-5 + d404 *
      3.9591613690338653E-5) + d309 * 0.00039056873926796671) + d310 * 0.00039056873926796671)) + (((d311 *
      0.00039056873926796671 + d343 * 0.0002419423961698487) + d239 * 0.0002419423961698487) + d241 *
      0.0002419423961698487)) + (((d344 * 0.000306810451202342 + d345 * 0.000306810451202342) + d346 *
      0.000306810451202342) - d313 * 0.00039056873926796671)) + (((d348 * -0.0002419423961698487 - d349 *
      0.000306810451202342) - d315 * 0.000282008223629501) + d317 * 0.0031245499141437328)) + (((d246 *
      -0.00039119388738803059 - d247 * 0.00039119388738803059) + d327 * 0.0001446502557068039) + d328 *
      0.0001446502557068039)) + (((d329 * 0.0001446502557068039 + d318 * 0.000282008223629501) + d319 *
      0.000282008223629501) + d320 * 0.000282008223629501)) + ((d350 * 0.00049792824183396965 + d351 *
      0.00049792824183396965) - d331 * 0.001410643421579826)) + ((d333 * -0.001410643421579826 - d335 *
      0.001410643421579826) + d352 * 0.00049792824183396965)) + (((d353 * 0.00049792824183396965 - d322 *
      0.0031245499141437328) - d324 * 0.0031245499141437328) - d326 * 0.0031245499141437328)) + ((d336 *
      -0.0001446502557068039 + d295 * 0.00039119388738803059) + d296 * 0.00039119388738803059)) + (((d338 *
      0.001410643421579826 - d339 * 0.0015622749570718671) - d340 * 0.0015622749570718671) - d341 *
      0.0015622749570718671)) + (((d354 * -0.0003225898615597983 - d355 * 0.0003225898615597983) - d356 *
      0.0003225898615597983) + d342 * 0.0015622749570718671)) + (((d357 * -0.0004090806016031226 - d358 *
      0.0004090806016031226) - d359 * 0.0004090806016031226) + d360 * 0.0003225898615597983)) + (((d361 *
      0.0004090806016031226 + e_coriolis_current_tmp * 0.0001048305173209615) + f_coriolis_current_tmp *
      0.0001048305173209615) + g_coriolis_current_tmp * 0.0001048305173209615)) + ((i_coriolis_current_tmp *
      -0.00013343274745087171 - j_coriolis_current_tmp * 0.00013343274745087171) - k_coriolis_current_tmp *
      0.00013343274745087171)) + ((l_coriolis_current_tmp * -0.0001048305173209615 + m_coriolis_current_tmp *
      0.00013343274745087171) + n_coriolis_current_tmp * 0.0001955969436940153)) + ((o_coriolis_current_tmp *
      0.0001955969436940153 + p_coriolis_current_tmp * 0.0001955969436940153) - q_coriolis_current_tmp *
      0.00024896412091698482)) + ((r_coriolis_current_tmp * -0.00024896412091698482 - s_coriolis_current_tmp *
      0.00024896412091698482) - t_coriolis_current_tmp * 0.0001955969436940153)) + ((u_coriolis_current_tmp *
      3.9591613690338653E-5 + v_coriolis_current_tmp * 0.00024896412091698482) - w_coriolis_current_tmp *
      5.039389221500199E-5)) + ((d363 * 0.0001446502557068039 - d365 * 0.001410643421579826) - x_coriolis_current_tmp *
      3.9591613690338653E-5)) + ((y_coriolis_current_tmp * -3.9591613690338653E-5 - ab_coriolis_current_tmp *
      3.9591613690338653E-5) + t101 * 5.039389221500199E-5)) + ((t19 * 5.039389221500199E-5 + t16 * 5.039389221500199E-5)
      - d366 * 0.0001446502557068039)) + (((d368 * -0.0001446502557068039 - d369 * 0.0001446502557068039) - d370 *
      0.0004090806016031226) + d371 * 0.001410643421579826)) + (((d373 * 0.001410643421579826 + d374 *
      0.001410643421579826) + d375 * 0.0003225898615597983) + d376 * 0.0004090806016031226)) + (((d383 *
      0.0004090806016031226 + d302 * 0.0004090806016031226) - d384 * 0.00070532171078991322) - d385 *
      0.00070532171078991322)) + ((d393 * -0.00070532171078991322 - d394 * 7.2325127853401961E-5) - d395 *
      7.2325127853401961E-5)) + (((d398 * -7.2325127853401961E-5 - d399 * 0.0003225898615597983) - d400 *
      0.0003225898615597983) - d401 * 0.0003225898615597983)) + (((d306 * 8.0647465389949575E-5 + d307 *
      8.0647465389949575E-5) + d308 * 8.0647465389949575E-5) + d403 * 0.00070532171078991322)) + (((d405 *
      7.2325127853401961E-5 + d406 * 0.00010227015040078071) + d407 * 0.00010227015040078071) + d408 *
      0.00010227015040078071)) + (((t102 * -8.0647465389949575E-5 - t92 * 0.00010227015040078071) - t81 *
      7.91832273806773E-5) + t82 * 0.000100787784430004)) + ((t83 * -0.00028930051141360779 + t88 * 0.000100787784430004)
      + t89 * 0.0028212868431596529)) + ((t91 * 7.91832273806773E-5 + t68 * 7.91832273806773E-5) + t127 *
      7.91832273806773E-5)) + ((t103 * 7.91832273806773E-5 - t113 * 0.000100787784430004) + t114 *
      0.00028930051141360779)) + ((t94 * -0.000100787784430004 + t96 * 0.00028930051141360779) - t97 *
      0.000100787784430004)) + ((t98 * 0.00028930051141360779 - t128 * 0.000100787784430004) - t151 *
      0.000100787784430004)) + ((t148 * -0.000100787784430004 - t149 * 0.0028212868431596529) - t150 *
      0.0028212868431596529)) + ((t136 * -0.0028212868431596529 - t146 * 7.91832273806773E-5) - t253 *
      7.91832273806773E-5)) + (((t247 * -7.91832273806773E-5 + t185 * 0.00081816120320624521) - t181 *
      0.0006451797231195966) - t168 * 0.0001446502557068039)) + (((t167 * -0.0001446502557068039 - t165 *
      0.0001446502557068039) - t166 * 0.0006451797231195966) - t164 * 0.00081816120320624521)) + (((t162 *
      -0.00081816120320624521 - t139 * 0.00081816120320624521) + t141 * 0.001410643421579826) + t145 *
      0.001410643421579826)) + ((t147 * 0.001410643421579826 + t135 * 0.0028212868431596529) + t130 *
                0.0028212868431596529)) + (((ct_idx_193 * 0.0028212868431596529 - ct_idx_194 * 0.00081816120320624521) +
                ct_idx_195 * 0.0006451797231195966) + ct_idx_196 * 0.0006451797231195966)) + (((t280 *
                0.0006451797231195966 + t281 * 0.0001446502557068039) + t279 * 0.00028930051141360779) + t264 *
              0.00028930051141360779)) + (((t260 * 0.0006451797231195966 + t215 * 0.00028930051141360779) + t216 *
              0.0006451797231195966) + t217 * 0.0006451797231195966)) + (((t218 * -0.001410643421579826 - t219 *
              0.0028212868431596529) + t220 * 0.00081816120320624521) + t222 * 0.00081816120320624521)) + (((t209 *
             0.00081816120320624521 - t210 * 0.00028930051141360779) - t211 * 0.0003225898615597983) - t208 *
           0.0003225898615597983)) + (((t207 * -0.0003225898615597983 - t206 * 0.0004090806016031226) - t184 *
           0.0004090806016031226) - t187 * 0.0004090806016031226)) + (((t190 * 0.0003225898615597983 - t193 *
           0.0004090806016031226) - t194 * 0.0004090806016031226) - t195 * 0.0004090806016031226)) + (((t196 *
          0.0004090806016031226 + t197 * 0.0003225898615597983) + t204 * 0.0003225898615597983) + t183 *
        0.0003225898615597983)) + (t178 * 0.0004090806016031226 - t179 * 0.0003225898615597983);
    d7 = ct_idx_199 * t47;
    d55 = t25 * t47;
    d57 = t26 * t47;
    d59 = ct_idx_199 * t59;
    d61 = t25 * t59;
    d65 = t26 * t59;
    d66 = ct_idx_199 * t80;
    d67 = t25 * t80;
    d69 = t112 * ct_idx_199;
    d70 = t112 * t25;
    d71 = t112 * t26;
    d72 = t126 * ct_idx_199;
    d73 = t126 * t25;
    d75 = t126 * t26;
    d76 = t161 * ct_idx_199;
    d77 = t161 * t25;
    d78 = t176 * ct_idx_199;
    d79 = t214 * ct_idx_199;
    d80 = ct_idx_197 * ct_idx_199;
    d83 = ct_idx_199 * ct_idx_227;
    d84 = d10 * t47;
    d105 = d10 * t59;
    d106 = d10 * t112;
    d117 = d10 * t126;
    d119 = d10 * t9;
    coriolis_current[3] =
      ((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((ct_idx_199 * t4 *
      0.0072996002294296652 + t25 * t4 * 0.01459920045885933) + t26 * t4 * 0.01459920045885933) + d23 *
      0.0030143386037902028) + (((ct_idx_199 * t9 * -8.4438500424373184E-5 - t25 * t9 * 0.0001688770008487464) - t26 *
      t9 * 0.0001688770008487464) - d74 * 3.1154816239901759E-5)) + (((d2 * 0.0078244665160454082 - d7 *
      0.0010024632241038541) + d3 * 0.01564893303209082) - d55 * 0.0020049264482077068)) + (((d57 *
      -0.0020049264482077068 - d5 * 9.0509918142080915E-5) + d59 * 0.000533656652986557) - d25 * 0.0001810198362841618))
      + (((d61 * 0.0010673133059731141 + d65 * 0.0010673133059731141) - d26 * 0.001074543767334554) - d27 *
      0.0021490875346691081)) + (((d66 * 0.00057202839622964223 + d67 * 0.001144056792459284) + d69 *
      0.0010024632241038541) + d70 * 0.0020049264482077068)) + (((d71 * 0.0020049264482077068 + d72 *
      0.000533656652986557) + d73 * 0.0010673133059731141) + d75 * 0.0010673133059731141)) + (((d81 *
      0.0078244665160454082 - d82 * 9.0509918142080915E-5) + d28 * 0.001074543767334554) + d29 * 0.0021490875346691081))
      + (((d76 * 0.00057202839622964223 + d77 * 0.001144056792459284) - d85 * 0.001074543767334554) + d78 *
      0.00057202839622964223)) + (((d86 * 0.0072996002294296652 - d87 * 8.4438500424373184E-5) - d88 *
      0.0010024632241038541) + d79 * 0.000533656652986557)) + (((d89 * 0.002300271973464899 - d90 *
      0.0028087584496889451) + d91 * 0.001074543767334554) + d80 * 0.00057202839622964223)) + (((d92 *
      0.0015071693018951021 - d93 * 1.557740811995088E-5) + d94 * 0.0010024632241038541) + d83 * 0.000533656652986557))
      + (((d95 * 0.000281833869642731 + d96 * 0.00019123336564369511) + d97 * 0.0015071693018951021) - d98 *
      0.000281833869642731)) + (((d101 * 1.557740811995088E-5 + d102 * 0.00019123336564369511) + d198 *
      0.029198400917718661) - d119 * 0.00033775400169749268)) + (((d100 * 0.00013141163080916381 + d104 *
      0.00013141163080916381) + d108 * 0.00013141163080916381) + d30 * 0.00018656004875664269)) + (((d31 *
      0.00018656004875664269 + d34 * 0.00018656004875664269) + d24 * 0.007133267858936608) - d109 *
      0.0022546709571418478)) + (((d110 * -0.0022546709571418478 - d112 * 0.00070711711979277428) - d113 *
      0.0022546709571418478) - d114 * 0.00070711711979277428)) + (((d115 * -0.00070711711979277428 + d35 *
      0.0020367670043187429) + d38 * 0.0020367670043187429) - d84 * 0.0040098528964154136)) + (((d116 *
      0.0027236935369322488 + d39 * 0.0020367670043187429) + d118 * 0.0027236935369322488) + d123 *
      0.0027236935369322488)) + (((d105 * 0.0021346266119462282 - d125 * 0.01317994506928148) - d126 *
      0.0030143386037902028) + d127 * 3.1154816239901759E-5)) + (((d106 * 0.0040098528964154136 + d117 *
      0.0021346266119462282) - d135 * 0.0011273354785709239) - d136 * 0.00076493346257478021)) + (((d137 *
      -0.0030143386037902028 + d138 * 0.0011273354785709239) - d139 * 3.1154816239901759E-5) - d140 *
      0.00076493346257478021)) + (((d42 * -0.0002304185909016788 - d64 * t25 * 0.00046083718180335771) - d64 * t26 *
      0.00046083718180335771) + d44 * 0.0001623052899103674)) + (((d144 * 6.5705815404581917E-5 + d6 * t25 *
      0.00032461057982073491) + d145 * 6.5705815404581917E-5) + d6 * t26 * 0.00032461057982073491)) + (((d151 *
      9.3280024378321344E-5 + d152 * 0.00055233577423126736) + d20 * 9.3280024378321344E-5) - d21 *
      0.00055233577423126736)) + (((d153 * 0.00043173120535653731 - d22 * 0.00043173120535653731) - d154 *
      0.00070711711979277428) + d155 * 0.0027236935369322488)) + (((d220 * -0.00092167436360671541 + d198 * t11 *
      0.0006492211596414697) + d161 * 0.00018656004875664269) - d167 * 0.00013141163080916381)) + (((d168 *
      0.00086346241071307472 + d169 * 0.00086346241071307472) + d172 * 0.00086346241071307472) - d173 *
      0.0011046715484625349)) + (((d174 * -0.0011046715484625349 - d175 * 0.0011046715484625349) + d176 *
      0.0054473870738644976) - d179 * 0.00055233577423126736)) + (((d180 * -0.00055233577423126736 - d181 *
      0.00055233577423126736) - d184 * 0.00043173120535653731) - d185 * 0.00043173120535653731)) + (((d189 *
      -0.00043173120535653731 + d190 * 0.001414234239585549) + d196 * 0.00070711711979277428) + d201 *
      0.00070711711979277428)) + (((d203 * 0.00070711711979277428 - d204 * 0.0027236935369322488) - d195 *
      0.0027236935369322488) - d262 * 0.0027236935369322488)) + (((d197 * -0.0027236935369322488 - d205 *
      0.0027236935369322488) - d202 * 0.0027236935369322488) - d263 * 0.00070711711979277428)) + (((d264 *
      -0.00070711711979277428 - d265 * 0.00070711711979277428) - d231 * 0.00024698647768624672) - d40 *
      0.00049397295537249343)) + (((d232 * 0.00017397559679510521 + d41 * 0.00034795119359021042) + d234 *
      0.0001623052899103674) + t73 * t25 * 0.00032461057982073491)) + (((t73 * t26 * 0.00032461057982073491 + d235 *
      0.00024698647768624672) + d49 * 0.00049397295537249343) + d236 * 0.0002304185909016788)) + (((t49 * t25 *
      0.00046083718180335771 + t49 * t26 * 0.00046083718180335771) - d237 * 0.00017397559679510521) - d50 *
      0.00034795119359021042)) + (((d242 * 0.000891658482367076 + d243 * 0.000891658482367076) + d244 *
      0.000891658482367076) - d245 * 0.000891658482367076)) + (((d254 * 0.003566633929468304 + d255 *
      0.003566633929468304) + d256 * 0.003566633929468304) + d221 * t9 * 0.0006492211596414697)) + (((d257 *
      -0.003566633929468304 + d188 * t9 * t11 * 0.00092167436360671541) + d258 * 0.00017397559679510521) + d259 *
      0.00017397559679510521)) + ((d51 * 0.00034795119359021042 + d52 * 0.00034795119359021042) + d260 *
      0.00024698647768624672)) + ((d261 * 0.00024698647768624672 + d53 * 0.00049397295537249343) + d54 *
      0.00049397295537249343)) + ((d60 * -0.00024698647768624672 + d68 * 0.00017397559679510521) + d99 *
      0.00024698647768624672)) + ((d107 * 0.00024698647768624672 + d142 * 0.00024698647768624672) - d162 *
      0.00017397559679510521)) + ((d177 * -0.00017397559679510521 - d191 * 0.00017397559679510521) - d209 *
      0.0002304185909016788)) + (((d218 * 0.0001623052899103674 + d222 * 0.0002304185909016788) + d223 *
      0.0002304185909016788) + d224 * 0.0002304185909016788)) + (((t87 * -0.0001623052899103674 - t12 *
      0.0001623052899103674) - d228 * 0.0001623052899103674) + d381 * 9.3280024378321344E-5)) + (((d382 *
      9.3280024378321344E-5 + d389 * 9.3280024378321344E-5) - d391 * 6.5705815404581917E-5) - d392 *
      6.5705815404581917E-5)) + (((d397 * -6.5705815404581917E-5 - d402 * 9.3280024378321344E-5) + d404 *
      6.5705815404581917E-5) - d309 * 0.000891658482367076)) + (((d310 * -0.000891658482367076 - d311 *
      0.000891658482367076) + d343 * 0.0020427701526991868) + d239 * 0.0020427701526991868)) + (((d241 *
      0.0020427701526991868 + d344 * 0.00053033783984458068) + d345 * 0.00053033783984458068) + d346 *
      0.00053033783984458068)) + (((d313 * 0.000891658482367076 - d348 * 0.0020427701526991868) - d349 *
      0.00053033783984458068) - d317 * 0.007133267858936608)) + ((d327 * 0.00055233577423126736 + d328 *
      0.00055233577423126736) + d329 * 0.00055233577423126736)) + (((d331 * 0.00043173120535653731 + d333 *
      0.00043173120535653731) + d335 * 0.00043173120535653731) + d322 * 0.007133267858936608)) + (((d324 *
      0.007133267858936608 + d326 * 0.007133267858936608) - d336 * 0.00055233577423126736) - d338 *
      0.00043173120535653731)) + (((d339 * 0.003566633929468304 + d340 * 0.003566633929468304) + d341 *
      0.003566633929468304) - d354 * 0.0027236935369322488)) + (((d355 * -0.0027236935369322488 - d356 *
      0.0027236935369322488) - d342 * 0.003566633929468304) - d357 * 0.00070711711979277428)) + (((d358 *
      -0.00070711711979277428 - d359 * 0.00070711711979277428) + d360 * 0.0027236935369322488) + d361 *
      0.00070711711979277428)) + ((e_coriolis_current_tmp * 0.00017397559679510521 + f_coriolis_current_tmp *
      0.00017397559679510521) + g_coriolis_current_tmp * 0.00017397559679510521)) + ((i_coriolis_current_tmp *
      0.00024698647768624672 + j_coriolis_current_tmp * 0.00024698647768624672) + k_coriolis_current_tmp *
      0.00024698647768624672)) + ((l_coriolis_current_tmp * -0.00017397559679510521 - m_coriolis_current_tmp *
      0.00024698647768624672) + n_coriolis_current_tmp * 0.0001623052899103674)) + (((o_coriolis_current_tmp *
      0.0001623052899103674 + p_coriolis_current_tmp * 0.0001623052899103674) + q_coriolis_current_tmp *
      0.0002304185909016788) + r_coriolis_current_tmp * 0.0002304185909016788)) + ((s_coriolis_current_tmp *
      0.0002304185909016788 - t_coriolis_current_tmp * 0.0001623052899103674) + u_coriolis_current_tmp *
      6.5705815404581917E-5)) + ((v_coriolis_current_tmp * -0.0002304185909016788 + w_coriolis_current_tmp *
      9.3280024378321344E-5) + d363 * 0.00055233577423126736)) + ((d365 * 0.00043173120535653731 -
      x_coriolis_current_tmp * 6.5705815404581917E-5) - y_coriolis_current_tmp * 6.5705815404581917E-5)) +
      ((ab_coriolis_current_tmp * -6.5705815404581917E-5 - t101 * 9.3280024378321344E-5) - t19 * 9.3280024378321344E-5))
      + ((t16 * -9.3280024378321344E-5 - d366 * 0.00055233577423126736) - d368 * 0.00055233577423126736)) + (((d369 *
      -0.00055233577423126736 - d370 * 0.00070711711979277428) - d371 * 0.00043173120535653731) - d373 *
      0.00043173120535653731)) + (((d374 * -0.00043173120535653731 + d375 * 0.0027236935369322488) + d376 *
      0.00070711711979277428) + d383 * 0.00070711711979277428)) + (((d302 * 0.00070711711979277428 + d384 *
      0.00021586560267826871) + d385 * 0.00021586560267826871) + d393 * 0.00021586560267826871)) + (((d394 *
      -0.00027616788711563368 - d395 * 0.00027616788711563368) - d398 * 0.00027616788711563368) - d399 *
      0.0027236935369322488)) + (((d400 * -0.0027236935369322488 - d401 * 0.0027236935369322488) + d306 *
      0.0006809233842330622) + d307 * 0.0006809233842330622)) + (((d308 * 0.0006809233842330622 - d403 *
      0.00021586560267826871) + d405 * 0.00027616788711563368) + d406 * 0.0001767792799481936)) + (((d407 *
      0.0001767792799481936 + d408 * 0.0001767792799481936) - t102 * 0.0006809233842330622) - t92 *
      0.0001767792799481936)) + ((t81 * -0.00013141163080916381 - t82 * 0.00018656004875664269) - t83 *
      0.0011046715484625349)) + ((t88 * -0.00018656004875664269 - t89 * 0.00086346241071307472) + t91 *
      0.00013141163080916381)) + ((t68 * 0.00013141163080916381 + t127 * 0.00013141163080916381) + t103 *
      0.00013141163080916381)) + ((t113 * 0.00018656004875664269 + t114 * 0.0011046715484625349) + t94 *
      0.00018656004875664269)) + ((t96 * 0.0011046715484625349 + t97 * 0.00018656004875664269) + t98 *
      0.0011046715484625349)) + ((t128 * 0.00018656004875664269 + t151 * 0.00018656004875664269) + t148 *
      0.00018656004875664269)) + ((t149 * 0.00086346241071307472 + t150 * 0.00086346241071307472) + t136 *
      0.00086346241071307472)) + (((t146 * -0.00013141163080916381 - t253 * 0.00013141163080916381) - t247 *
      0.00013141163080916381) + t185 * 0.001414234239585549)) + ((t181 * -0.0054473870738644976 - t168 *
      0.00055233577423126736) - t167 * 0.00055233577423126736)) + (((t165 * -0.00055233577423126736 - t166 *
      0.0054473870738644976) - t164 * 0.001414234239585549) - t162 * 0.001414234239585549)) + ((t139 *
      -0.001414234239585549 - t141 * 0.00043173120535653731) - t145 * 0.00043173120535653731)) + ((t147 *
      -0.00043173120535653731 - t135 * 0.00086346241071307472) - t130 * 0.00086346241071307472)) + (((ct_idx_193 *
      -0.00086346241071307472 - ct_idx_194 * 0.001414234239585549) + ct_idx_195 * 0.0054473870738644976) + ct_idx_196 *
               0.0054473870738644976)) + (((t280 * 0.0054473870738644976 + t281 * 0.00055233577423126736) + t279 *
               0.0011046715484625349) + t264 * 0.0011046715484625349)) + (((t260 * 0.0054473870738644976 + t215 *
               0.0011046715484625349) + t216 * 0.0054473870738644976) + t217 * 0.0054473870738644976)) + (((t218 *
              0.00043173120535653731 + t219 * 0.00086346241071307472) + t220 * 0.001414234239585549) + t222 *
            0.001414234239585549)) + (((t209 * 0.001414234239585549 - t210 * 0.0011046715484625349) - t211 *
            0.0027236935369322488) - t208 * 0.0027236935369322488)) + (((t207 * -0.0027236935369322488 - t206 *
            0.00070711711979277428) - t184 * 0.00070711711979277428) - t187 * 0.00070711711979277428)) + (((t190 *
           0.0027236935369322488 - t193 * 0.00070711711979277428) - t194 * 0.00070711711979277428) - t195 *
         0.00070711711979277428)) + (((t196 * 0.00070711711979277428 + t197 * 0.0027236935369322488) + t204 *
         0.0027236935369322488) + t183 * 0.0027236935369322488)) + (t178 * 0.00070711711979277428 - t179 *
      0.0027236935369322488);
    d2 = ct_idx_199 * t43;
    d3 = t25 * t43;
    d5 = t26 * t43;
    d6 = t27 * t43;
    d20 = d17 * t10;
    d21 = d18 * t10;
    d22 = d19 * t10;
    d23 = d10 * t43;
    d24 = d11 * t43;
    d25 = d12 * t43;
    d30 = t10 * ct_idx_199;
    d31 = t25 * t33;
    d34 = t26 * t33;
    d35 = t27 * t33;
    d38 = d10 * t33;
    d39 = d11 * t33;
    d40 = d12 * t33;
    d41 = d64 * t10;
    d49 = t10 * t4 * t11;
    d50 = t10 * t5;
    d51 = d206 * t10;
    d52 = d56 * t10 * t11;
    d53 = t48 * t10;
    d54 = t60 * t10 * t11;
    d56 = d50 * ct_idx_199;
    d60 = d8 * t2;
    d64 = d60 * t5;
    d68 = d8 * t3;
    d74 = d68 * t5;
    d81 = d9 * t2;
    d82 = d81 * t5;
    d86 = d9 * t3;
    d87 = d86 * t5;
    d89 = d * t2;
    d90 = d51 * ct_idx_199;
    d99 = d52 * ct_idx_199;
    d100 = d53 * ct_idx_199;
    d104 = d54 * ct_idx_199;
    d107 = d41 * ct_idx_199;
    d108 = d49 * ct_idx_199;
    d109 = d32 * t10 * ct_idx_199;
    d110 = t10 * t9 * t11 * ct_idx_199;
    d112 = d56 * ct_idx_283;
    d113 = d56 * ct_idx_284;
    d114 = d60 * t3;
    d115 = d81 * t3;
    d116 = d89 * t3;
    d118 = d * t3;
    d120 = d64 * t6 * t8;
    d121 = d74 * t6 * t7;
    d122 = d82 * t6 * t8;
    d123 = d87 * t6 * t7;
    d64 *= t8;
    d74 *= t7;
    d82 *= t8;
    d87 *= t7;
    d124 = d60 * t4;
    d125 = d68 * t4;
    d126 = d81 * t4;
    d127 = d86 * t4;
    d128 = d89 * t4;
    d129 = d118 * t4;
    d131 = d114 * t9;
    d132 = d124 * t8;
    d133 = d125 * t7;
    d134 = d115 * t9;
    d135 = d126 * t8;
    d136 = d127 * t7;
    d137 = d116 * t9;
    d138 = d128 * t8;
    d139 = d129 * t7;
    d140 = d8 * t7;
    d141 = d140 * t8 * t9;
    d142 = d9 * t7 * t8 * t9;
    d143 = d * t7 * t8 * t9;
    d62 = d62 * t10 * t11 * ct_idx_199;
    d144 = d230 * t10 * t11 * ct_idx_199;
    d145 = d233 * t10 * t11 * ct_idx_199;
    d146 = d112 * ct_idx_284;
    d147 = t25 * t6;
    d148 = t26 * t6;
    d149 = t27 * t6;
    d150 = t11 * t25;
    d151 = t11 * t26;
    d152 = t11 * t27;
    d153 = d10 * t11;
    d154 = d11 * t11;
    d155 = d12 * t11;
    d156 = t107 * ct_idx_291;
    d157 = c_coriolis_current_tmp * ct_idx_262 * ct_idx_290;
    d158 = t52 * ct_idx_262 * t40;
    d159 = t15 * ct_idx_291;
    d160 = d_coriolis_current_tmp * ct_idx_262 * ct_idx_290;
    d161 = t54 * ct_idx_262 * t40;
    d162 = d362 * ct_idx_291;
    d164 = d297 * ct_idx_262 * ct_idx_290;
    d165 = d367 * ct_idx_262 * t40;
    d166 = d364 * ct_idx_291;
    d167 = d300 * ct_idx_262 * ct_idx_290;
    d168 = d372 * ct_idx_262 * t40;
    d169 = d380 * ct_idx_262;
    d172 = d43 * t40 * ct_idx_290 * ct_idx_291;
    d173 = d390 * ct_idx_262;
    d174 = d45 * t40 * ct_idx_290 * ct_idx_291;
    d175 = d46 * t40 * ct_idx_290 * ct_idx_291;
    d176 = d30 * t30;
    d177 = d47 * t40 * ct_idx_290 * ct_idx_291;
    d179 = d378 * ct_idx_262;
    d180 = d386 * ct_idx_262;
    d181 = d238 * ct_idx_262;
    d183 = d48 * ct_idx_290 * ct_idx_291;
    d184 = d240 * t40 * ct_idx_291;
    d185 = ct_idx_199 * ct_idx_262;
    d187 = d185 * t40 * ct_idx_290;
    d189 = d114 * t4;
    d190 = d189 * t5;
    d191 = d115 * t4;
    d192 = d191 * t5;
    d195 = d116 * t4;
    d196 = d195 * t5;
    d197 = d8 * t4;
    d199 = d197 * t5;
    d200 = d9 * t4;
    c_coriolis_current_tmp = d200 * t5;
    d_coriolis_current_tmp = d89 * t5;
    e_coriolis_current_tmp = d118 * t5;
    f_coriolis_current_tmp = d1 * t5;
    g_coriolis_current_tmp = d64 * t9;
    i_coriolis_current_tmp = d74 * t9;
    j_coriolis_current_tmp = d199 * t7 * t8;
    k_coriolis_current_tmp = d82 * t9;
    l_coriolis_current_tmp = d87 * t9;
    m_coriolis_current_tmp = c_coriolis_current_tmp * t7 * t8;
    n_coriolis_current_tmp = d_coriolis_current_tmp * t8 * t9;
    o_coriolis_current_tmp = e_coriolis_current_tmp * t7 * t9;
    p_coriolis_current_tmp = f_coriolis_current_tmp * t7 * t8;
    q_coriolis_current_tmp = d292 * t5 * t9;
    r_coriolis_current_tmp = d293 * t5 * t8;
    s_coriolis_current_tmp = d294 * t5 * t7;
    t_coriolis_current_tmp = n_coriolis_current_tmp_tmp * t7 * t8 * t9;
    u_coriolis_current_tmp = d190 * t6;
    v_coriolis_current_tmp = d192 * t6;
    w_coriolis_current_tmp = d196 * t6;
    x_coriolis_current_tmp = d120 * t9;
    y_coriolis_current_tmp = d121 * t9;
    ab_coriolis_current_tmp = d199 * t6 * t7 * t8;
    t101 = d122 * t9;
    t102 = d123 * t9;
    c_coriolis_current_tmp = c_coriolis_current_tmp * t6 * t7 * t8;
    d_coriolis_current_tmp = d_coriolis_current_tmp * t6 * t8 * t9;
    e_coriolis_current_tmp = e_coriolis_current_tmp * t6 * t7 * t9;
    f_coriolis_current_tmp = f_coriolis_current_tmp * t6 * t7 * t8;
    t92 = d62 * ct_idx_284;
    t81 = d144 * ct_idx_283;
    t82 = d145 * ct_idx_283;
    h_coriolis_current_tmp = h_coriolis_current_tmp * t10 * ct_idx_199;
    t83 = coriolis_current_tmp_tmp * t10 * ct_idx_199;
    t88 = b_coriolis_current_tmp_tmp * t10 * ct_idx_199;
    t89 = coriolis_current_tmp_tmp_tmp * t7;
    t91 = d189 * t10;
    t68 = d114 * t6 * t9;
    t127 = d124 * t6 * t8;
    t103 = d125 * t6 * t7;
    t113 = d191 * t10;
    t114 = d115 * t6 * t9;
    t94 = d126 * t6 * t8;
    t96 = d127 * t6 * t7;
    t97 = d195 * t10;
    t98 = d116 * t6 * t9;
    t128 = d128 * t6 * t8;
    t151 = d129 * t6 * t7;
    t148 = d131 * t11;
    t149 = d132 * t11;
    t150 = d133 * t11;
    t136 = d60 * t6 * t8;
    t146 = d68 * t6 * t7;
    t253 = d134 * t11;
    t247 = d135 * t11;
    t185 = d136 * t11;
    t181 = d81 * t6 * t8;
    t168 = d86 * t6 * t7;
    t167 = d137 * t11;
    t165 = d138 * t11;
    t166 = d139 * t11;
    coriolis_current_tmp_tmp = d60 * t8;
    t164 = coriolis_current_tmp_tmp * t9 * t10;
    b_coriolis_current_tmp_tmp = d68 * t7;
    t162 = b_coriolis_current_tmp_tmp * t9 * t10;
    t139 = d197 * t7 * t8 * t10;
    t141 = t89 * t8 * t9;
    n_coriolis_current_tmp_tmp = d81 * t8;
    t145 = n_coriolis_current_tmp_tmp * t9 * t10;
    t107 = d86 * t7;
    t147 = t107 * t9 * t10;
    t135 = d200 * t7 * t8 * t10;
    t130 = b_coriolis_current_tmp_tmp_tmp * t7 * t8 * t9;
    ct_idx_193 = d89 * t8 * t9 * t10;
    ct_idx_194 = d118 * t7 * t9 * t10;
    ct_idx_195 = d1 * t7 * t8 * t10;
    ct_idx_196 = c_coriolis_current_tmp_tmp_tmp * t7 * t8 * t9;
    t280 = d141 * t11;
    t281 = d142 * t11;
    t279 = d143 * t11;
    t264 = d189 * t6 * t10;
    t260 = d191 * t6 * t10;
    t215 = d195 * t6 * t10;
    t216 = t91 * t11;
    t217 = t113 * t11;
    t218 = t97 * t11;
    t219 = t136 * t9 * t10;
    t220 = t146 * t9 * t10;
    t222 = d197 * t6 * t7 * t8 * t10;
    t209 = t181 * t9 * t10;
    t210 = t168 * t9 * t10;
    t211 = d200 * t6 * t7 * t8 * t10;
    t208 = d89 * t6 * t8 * t9 * t10;
    t207 = d118 * t6 * t7 * t9 * t10;
    t206 = d1 * t6 * t7 * t8 * t10;
    t184 = t164 * t11;
    t187 = t162 * t11;
    t190 = t139 * t11;
    t193 = t145 * t11;
    t194 = t147 * t11;
    t195 = t135 * t11;
    t196 = ct_idx_193 * t11;
    t197 = ct_idx_194 * t11;
    t204 = ct_idx_195 * t11;
    coriolis_current[4] =
      (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
      ((((((((d290 * -3.36187823110059E-5 + d30 * 0.00098079157131581514) - t29 * t6 * 6.3743019125573471E-6) + t11 *
      t29 * 0.001214004802476556) + (((d312 * -0.00063603044665125059 + d31 * 0.001272060893302501) + d34 *
      0.001272060893302501) + d35 * 0.001272060893302501)) + (((d2 * -0.00068439641403297141 + d3 * 0.001368792828065943)
      + d5 * 0.001368792828065943) + d6 * 0.001368792828065943)) + (((d7 * -0.00085512578121433788 - d55 *
      0.001710251562428676) - d57 * 0.001710251562428676) - d59 * 2.9311311728143638E-5)) + (((d61 *
      -5.8622623456287277E-5 - d65 * 5.8622623456287277E-5) - d26 * 0.00091661225708541787) - d27 * 0.001833224514170836))
      + (((d66 * -3.14188955490441E-5 - d67 * 6.28377910980882E-5) - d69 * 0.00085512578121433788) - d70 *
      0.001710251562428676)) + (((d71 * -0.001710251562428676 + d72 * 2.9311311728143638E-5) + d73 *
      5.8622623456287277E-5) + d75 * 5.8622623456287277E-5)) + (((t142 * ct_idx_199 * 4.7787382277625531E-5 - t142 * t25
      * 9.5574764555251063E-5) - d28 * 0.00091661225708541787) - t142 * t26 * 9.5574764555251063E-5)) + (((d29 *
      -0.001833224514170836 - t142 * t27 * 9.5574764555251063E-5) + d76 * 3.14188955490441E-5) + d77 *
      6.28377910980882E-5)) + (((d85 * -0.00091661225708541787 - d78 * 3.14188955490441E-5) + t186 * ct_idx_199 *
      4.7787382277625531E-5) - t186 * t25 * 9.5574764555251063E-5)) + (((t186 * t26 * -9.5574764555251063E-5 - t186 *
      t27 * 9.5574764555251063E-5) - d88 * 0.00085512578121433788) - d79 * 2.9311311728143638E-5)) + (((d91 *
      -0.00091661225708541787 + d80 * 3.14188955490441E-5) - d92 * 0.0001380613496771573) + d93 * 6.076906936270857E-5))
      + (((d94 * -0.00085512578121433788 + d83 * 2.9311311728143638E-5) + d95 * 0.0003180152233256253) + d96 *
      0.00034219820701648571)) + (((d97 * 0.0001380613496771573 + d98 * 0.0003180152233256253) + d101 *
      6.076906936270857E-5) - d102 * 0.00034219820701648571)) + (((ct_idx_199 * ct_idx_257 * -4.7787382277625531E-5 +
      ct_idx_199 * ct_idx_265 * 4.7787382277625531E-5) - ct_idx_199 * ct_idx_270 * 2.3893691138812769E-5) + ct_idx_199 *
      ct_idx_272 * 4.7787382277625531E-5)) + (((ct_idx_199 * ct_idx_274 * 2.3893691138812769E-5 - ct_idx_199 *
      ct_idx_275 * 2.3893691138812769E-5) - ct_idx_199 * ct_idx_280 * 4.7787382277625531E-5) + ct_idx_199 * ct_idx_282 *
      2.3893691138812769E-5)) + (((d20 * 0.0007645981164420085 + d21 * 0.0007645981164420085) + d22 *
      0.0007645981164420085) + d38 * 0.0025441217866050019)) + (((d39 * 0.0025441217866050019 + d40 *
      0.0025441217866050019) - d13 * t34 * 5.0399208965540472E-5) - d8 * t45 * 0.003666449028341671)) + (((d23 *
      0.0027375856561318861 + d24 * 0.0027375856561318861) + d25 * 0.0027375856561318861) - d84 * 0.003420503124857352))
      + (((d13 * t44 * -0.0025062654794853621 - d8 * t57 * 0.00012567558219617639) - d105 * 0.00011724524691257459) - d8
      * t69 * 0.003420503124857352)) + (((d9 * t69 * -0.003420503124857352 - d8 * t78 * 0.0084551023554276846) - d8 *
      t79 * 0.00011724524691257459) - d9 * t78 * 0.0084551023554276846)) + (((d9 * t79 * -0.00011724524691257459 - d *
      t78 * 0.0084551023554276846) - d8 * t95 * 0.00055224539870862919) - d9 * t95 * 0.00055224539870862919)) + (((d *
      t95 * -0.00055224539870862919 - d17 * ct_idx_313 * 0.0003822990582210043) - d18 * ct_idx_313 *
      0.0003822990582210043) + d8 * t100 * 0.00024307627745083431)) + (((d19 * ct_idx_313 * -0.0003822990582210043 + d9 *
      t100 * 0.00024307627745083431) + d * t100 * 0.00024307627745083431) + d4 * t100 * 0.0003822990582210043)) + (((d8 *
      t111 * 0.003666449028341671 - d106 * 0.003420503124857352) - d8 * t125 * 0.00012567558219617639) + d117 *
      0.00011724524691257459)) + (((d17 * ct_idx_158 * -0.0003822990582210043 - d18 * ct_idx_158 * 0.0003822990582210043)
      - d19 * ct_idx_158 * 0.0003822990582210043) + d8 * t143 * 0.003420503124857352)) + (((d9 * t143 *
      0.003420503124857352 - d10 * t142 * 0.0001911495291105021) - d11 * t142 * 0.0001911495291105021) - d12 * t142 *
      0.0001911495291105021)) + (((d8 * t160 * -0.00011724524691257459 - d9 * t160 * 0.00011724524691257459) + d8 * t169
      * 0.001272060893302501) + d9 * t169 * 0.001272060893302501)) + (((d * t169 * 0.001272060893302501 + d8 * t175 *
      0.001368792828065943) + d9 * t175 * 0.001368792828065943) - d8 * t177 * 0.0001911495291105021)) + (((d * t175 *
      0.001368792828065943 - d9 * t177 * 0.0001911495291105021) - d * t177 * 0.0001911495291105021) - d4 * t177 *
      0.0003822990582210043)) + (((d8 * t182 * -0.0001911495291105021 - d9 * t182 * 0.0001911495291105021) - d * t182 *
      0.0001911495291105021) - d4 * t182 * 0.0001911495291105021)) + (((d10 * t186 * -0.0001911495291105021 - d11 * t186
      * 0.0001911495291105021) - d12 * t186 * 0.0001911495291105021) - d8 * t191 * 0.00055224539870862919)) + (((d8 *
      t192 * -0.001272060893302501 - d9 * t191 * 0.00055224539870862919) - d9 * t192 * 0.001272060893302501) - d * t191 *
      0.00055224539870862919)) + (((d * t192 * -0.001272060893302501 - d8 * t202 * 0.00024307627745083431) + d8 * t203 *
      0.001368792828065943) - d9 * t202 * 0.00024307627745083431)) + (((d9 * t203 * 0.001368792828065943 - d * t202 *
      0.00024307627745083431) - d8 * t205 * 0.0001911495291105021) + d * t203 * 0.001368792828065943)) + (((d9 * t205 *
      -0.0001911495291105021 + d4 * t202 * 0.0003822990582210043) - d * t205 * 0.0001911495291105021) + d4 * t205 *
      0.0003822990582210043)) + (((d8 * t221 * 0.0001911495291105021 + d9 * t221 * 0.0001911495291105021) + d * t221 *
      0.0001911495291105021) - d4 * t221 * 0.0001911495291105021)) + (((d8 * t241 * -9.5574764555251063E-5 - d9 * t241 *
      9.5574764555251063E-5) - d * t241 * 9.5574764555251063E-5) - d8 * t263 * 0.0001911495291105021)) + (((d9 * t263 *
      -0.0001911495291105021 - d * t263 * 0.0001911495291105021) - d8 * t267 * 9.5574764555251063E-5) - d4 * t263 *
      0.0001911495291105021)) + (((d8 * t268 * -9.5574764555251063E-5 - d9 * t267 * 9.5574764555251063E-5) - d9 * t268 *
      9.5574764555251063E-5) - d * t267 * 9.5574764555251063E-5)) + (((d * t268 * -9.5574764555251063E-5 + d8 * t282 *
      0.0001911495291105021) + d9 * t282 * 0.0001911495291105021) - d8 * t284 * 9.5574764555251063E-5)) + (((d * t282 *
      0.0001911495291105021 - d9 * t284 * 9.5574764555251063E-5) - d * t284 * 9.5574764555251063E-5) - d4 * t282 *
      0.0001911495291105021)) + (((d43 * -0.00010414202629241489 - d45 * 2.6520763113332569E-5) + d378 * t33 *
      3.187150956278674E-6) - d147 * t33 * 6.3743019125573471E-6)) + (((d148 * t33 * -6.3743019125573471E-6 - d149 * t33
      * 6.3743019125573471E-6) - d386 * t33 * 0.000607002401238278) + d150 * t33 * 0.001214004802476556)) + (((d151 *
      t33 * 0.001214004802476556 + d152 * t33 * 0.001214004802476556) + d2 * t44 * 6.2999011206925581E-6) - d3 * t44 *
      1.259980224138512E-5)) + (((d5 * t44 * -1.259980224138512E-5 - d6 * t44 * 1.259980224138512E-5) - d251 *
      1.2748603825114691E-5) - d252 * 1.2748603825114691E-5)) + (((d253 * -1.2748603825114691E-5 + d225 * t11 *
      0.002428009604953112) + d226 * t11 * 0.002428009604953112) + d227 * t11 * 0.002428009604953112)) + (((d282 * t33 *
      -1.2748603825114691E-5 - d283 * t33 * 1.2748603825114691E-5) - d284 * t33 * 1.2748603825114691E-5) + d153 * t33 *
      0.002428009604953112)) + (((d154 * t33 * 0.002428009604953112 + d155 * t33 * 0.002428009604953112) + d20 *
      ct_idx_287 * 0.00654172719185474) + d21 * ct_idx_287 * 0.00654172719185474)) + (((d22 * ct_idx_287 *
      0.00654172719185474 - d20 * t44 * 5.0399208965540472E-5) - d21 * t44 * 5.0399208965540472E-5) - d22 * t44 *
      5.0399208965540472E-5)) + (((d23 * t44 * -2.5199604482770229E-5 - d24 * t44 * 2.5199604482770229E-5) - d25 * t44 *
      2.5199604482770229E-5) - d107 * 0.00018159726122252709)) + (((d41 * t25 * -0.00036319452244505418 - d41 * t26 *
      0.00036319452244505418) - d108 * 4.6245479547226651E-5) - d49 * t25 * 9.2490959094453315E-5)) + (((d49 * t26 *
      -9.2490959094453315E-5 - d56 * ct_idx_287 * 0.00327086359592737) + d50 * t25 * ct_idx_287 * 0.00327086359592737) +
      d50 * t26 * ct_idx_287 * 0.00327086359592737)) + (((d50 * t27 * ct_idx_287 * 0.00327086359592737 -
      k_coriolis_current_tmp_tmp * t6 * t7 * 0.000778618907984901) - d220 * t10 * 0.00072638904489010837) -
      k_coriolis_current_tmp_tmp * t7 * t11 * 0.0001982827524043791)) + (((d198 * t10 * t11 * -0.0001849819181889066 +
      d188 * t10 * ct_idx_287 * 0.00654172719185474) + d193 * t10 * ct_idx_287 * 0.00654172719185474) + d194 * t10 *
      ct_idx_287 * 0.00654172719185474)) + ((d90 * -0.00019465472699622529 - d51 * t25 * 0.00038930945399245052) - d99 *
      4.9570688101094768E-5)) + ((d52 * t25 * -9.9141376202189536E-5 + d100 * 0.00019465472699622529) + d53 * t25 *
      0.00038930945399245052)) + (((d104 * 4.9570688101094768E-5 + d54 * t25 * 9.9141376202189536E-5) + d112 *
      ct_idx_287 * 0.00327086359592737) + d113 * ct_idx_287 * 0.00327086359592737)) + (((d56 * ct_idx_285 * ct_idx_287 *
      0.00327086359592737 - d120 * 0.00072638904489010837) - d121 * 0.00072638904489010837) - d122 *
      0.00072638904489010837)) + (((d123 * -0.00072638904489010837 - d64 * t11 * 0.0001849819181889066) - d74 * t11 *
      0.0001849819181889066) - d82 * t11 * 0.0001849819181889066)) + (((d87 * t11 * -0.0001849819181889066 + d316 * t34 *
      5.0399208965540472E-5) - d321 * t34 * 5.0399208965540472E-5) - d323 * t34 * 5.0399208965540472E-5)) + (((d325 *
      t34 * -5.0399208965540472E-5 - d131 * t44 * 2.5199604482770229E-5) - d132 * t44 * 2.5199604482770229E-5) - d133 *
      t44 * 2.5199604482770229E-5)) + (((d134 * t44 * -2.5199604482770229E-5 - d135 * t44 * 2.5199604482770229E-5) -
      d136 * t44 * 2.5199604482770229E-5) - d137 * t44 * 2.5199604482770229E-5)) + (((d138 * t44 *
      -2.5199604482770229E-5 - d139 * t44 * 2.5199604482770229E-5) + d141 * t44 * 2.5199604482770229E-5) + d142 * t44 *
      2.5199604482770229E-5)) + (((d143 * t44 * 2.5199604482770229E-5 - d62 * 0.00327086359592737) - d144 *
      0.00327086359592737) - d145 * 0.00327086359592737)) + ((d90 * t30 * -0.00019465472699622529 - d99 * t30 *
      4.9570688101094768E-5) + d100 * t30 * 0.00019465472699622529)) + ((d63 * t10 * ct_idx_199 * t40 *
      0.00019465472699622529 + d111 * t10 * ct_idx_199 * t40 * 0.00019465472699622529) + d104 * t30 *
      4.9570688101094768E-5)) + (((d163 * t10 * t11 * ct_idx_199 * t40 * 4.9570688101094768E-5 + d178 * t10 * t11 *
      ct_idx_199 * t40 * 4.9570688101094768E-5) - d107 * t30 * ct_idx_253 * 0.00018159726122252709) - d108 * t30 *
      ct_idx_253 * 4.6245479547226651E-5)) + (((d109 * t30 * ct_idx_290 * 0.00018159726122252709 + d109 * ct_idx_253 *
      t40 * 0.00018159726122252709) + d107 * t40 * ct_idx_290 * 0.00018159726122252709) + d110 * t30 * ct_idx_290 *
      4.6245479547226651E-5)) + (((d110 * ct_idx_253 * t40 * 4.6245479547226651E-5 + d108 * t40 * ct_idx_290 *
      4.6245479547226651E-5) + d156 * 0.000607002401238278) + d157 * 0.000607002401238278)) + (((d158 *
      0.000607002401238278 + d159 * 3.187150956278674E-6) + d160 * 3.187150956278674E-6) + d161 * 3.187150956278674E-6))
      + ((d162 * 3.67578781026004E-5 + d164 * 3.67578781026004E-5) + d165 * 3.67578781026004E-5)) + (((d166 *
      9.3607452477503928E-6 + d167 * 9.3607452477503928E-6) + d168 * 9.3607452477503928E-6) - d146 * ct_idx_287 *
      0.00654172719185474)) + (((d112 * ct_idx_285 * ct_idx_287 * -0.00654172719185474 - d113 * ct_idx_285 * ct_idx_287 *
      0.00654172719185474) - d169 * t33 * 3.187150956278674E-6) - d172 * 0.000607002401238278)) + ((d173 * t33 *
      0.000607002401238278 - d174 * 3.187150956278674E-6) - d175 * 3.67578781026004E-5)) + (((d177 *
      -9.3607452477503928E-6 - d176 * ct_idx_253 * t34 * ct_idx_291 * 1.259980224138512E-5) - d176 * ct_idx_262 * t34 *
      ct_idx_290 * 1.259980224138512E-5) - d30 * ct_idx_253 * ct_idx_262 * t34 * t40 * 1.259980224138512E-5)) + (((d379 *
      t33 * ct_idx_290 * ct_idx_291 * 3.187150956278674E-6 + d388 * t33 * t40 * ct_idx_291 * 3.187150956278674E-6) +
      d179 * t33 * t40 * ct_idx_290 * 3.187150956278674E-6) - d387 * t33 * ct_idx_290 * ct_idx_291 *
      0.000607002401238278)) + (((d396 * t33 * t40 * ct_idx_291 * -0.000607002401238278 - d180 * t33 * t40 * ct_idx_290 *
      0.000607002401238278) + d30 * t34 * t40 * ct_idx_290 * ct_idx_291 * 1.259980224138512E-5) - d181 * t43 * t44 *
      6.2999011206925581E-6)) + (((d183 * t43 * t44 * 6.2999011206925581E-6 + d184 * t43 * t44 * 6.2999011206925581E-6)
      + d187 * t43 * t44 * 6.2999011206925581E-6) - u_coriolis_current_tmp * 0.00014703151241040159)) +
      ((v_coriolis_current_tmp * -0.00014703151241040159 - w_coriolis_current_tmp * 0.00014703151241040159) - d190 * t11
      * 3.7442980991001571E-5)) + ((t264 * 0.002428009604953112 - d192 * t11 * 3.7442980991001571E-5) + t260 *
      0.002428009604953112)) + (((d196 * t11 * -3.7442980991001571E-5 + t215 * 0.002428009604953112) + t216 *
      1.2748603825114691E-5) + x_coriolis_current_tmp * 0.00014703151241040159)) + (((y_coriolis_current_tmp *
      0.00014703151241040159 + ab_coriolis_current_tmp * 0.00014703151241040159) + d410 * t11 * 0.00654172719185474) +
      t217 * 1.2748603825114691E-5)) + ((t101 * 0.00014703151241040159 + t102 * 0.00014703151241040159) +
      c_coriolis_current_tmp * 0.00014703151241040159)) + ((t218 * 1.2748603825114691E-5 + d_coriolis_current_tmp *
      0.00014703151241040159) + e_coriolis_current_tmp * 0.00014703151241040159)) + (((f_coriolis_current_tmp *
      0.00014703151241040159 + d327 * t10 * 1.2748603825114691E-5) + d328 * t10 * 1.2748603825114691E-5) + d329 * t10 *
      1.2748603825114691E-5)) + ((g_coriolis_current_tmp * t11 * 3.7442980991001571E-5 - t219 * 0.002428009604953112) +
      i_coriolis_current_tmp * t11 * 3.7442980991001571E-5)) + ((t220 * -0.002428009604953112 + j_coriolis_current_tmp *
      t11 * 3.7442980991001571E-5) - t222 * 0.002428009604953112)) + ((k_coriolis_current_tmp * t11 *
      3.7442980991001571E-5 - t209 * 0.002428009604953112) + l_coriolis_current_tmp * t11 * 3.7442980991001571E-5)) +
      ((t210 * -0.002428009604953112 + m_coriolis_current_tmp * t11 * 3.7442980991001571E-5) - t211 *
      0.002428009604953112)) + ((n_coriolis_current_tmp * t11 * 3.7442980991001571E-5 - t208 * 0.002428009604953112) +
      o_coriolis_current_tmp * t11 * 3.7442980991001571E-5)) + ((t207 * -0.002428009604953112 + p_coriolis_current_tmp *
      t11 * 3.7442980991001571E-5) - t206 * 0.002428009604953112)) + ((d330 * t10 * t11 * -0.002428009604953112 - d332 *
      t10 * t11 * 0.002428009604953112) - d334 * t10 * t11 * 0.002428009604953112)) + (((t184 * -1.2748603825114691E-5 -
      t187 * 1.2748603825114691E-5) - t190 * 1.2748603825114691E-5) - c_coriolis_current_tmp_tmp * t11 *
      0.00654172719185474)) + (((d_coriolis_current_tmp_tmp * t11 * -0.00654172719185474 - e_coriolis_current_tmp_tmp *
      t11 * 0.00654172719185474) - t193 * 1.2748603825114691E-5) - t194 * 1.2748603825114691E-5)) + (((t195 *
      -1.2748603825114691E-5 - t196 * 1.2748603825114691E-5) - t197 * 1.2748603825114691E-5) - t204 *
      1.2748603825114691E-5)) + (((d336 * t10 * -1.2748603825114691E-5 + d190 * t34 * 5.0399208965540472E-5) + d192 *
      t34 * 5.0399208965540472E-5) + d337 * t10 * t11 * 0.002428009604953112)) + (((d196 * t34 * 5.0399208965540472E-5 -
      g_coriolis_current_tmp * t34 * 5.0399208965540472E-5) - i_coriolis_current_tmp * t34 * 5.0399208965540472E-5) -
      j_coriolis_current_tmp * t34 * 5.0399208965540472E-5)) + (((k_coriolis_current_tmp * t34 * -5.0399208965540472E-5
      - l_coriolis_current_tmp * t34 * 5.0399208965540472E-5) - m_coriolis_current_tmp * t34 * 5.0399208965540472E-5) -
      n_coriolis_current_tmp * t34 * 5.0399208965540472E-5)) + (((o_coriolis_current_tmp * t34 * -5.0399208965540472E-5
      - p_coriolis_current_tmp * t34 * 5.0399208965540472E-5) + q_coriolis_current_tmp * ct_idx_287 *
      0.00654172719185474) + r_coriolis_current_tmp * ct_idx_287 * 0.00654172719185474)) + (((s_coriolis_current_tmp *
      ct_idx_287 * 0.00654172719185474 + t68 * t43 * 1.2748603825114691E-5) + t127 * t43 * 1.2748603825114691E-5) + t103
      * t43 * 1.2748603825114691E-5)) + (((t114 * t43 * 1.2748603825114691E-5 + t94 * t43 * 1.2748603825114691E-5) + t96
      * t43 * 1.2748603825114691E-5) + t98 * t43 * 1.2748603825114691E-5)) + (((t128 * t43 * 1.2748603825114691E-5 +
      t151 * t43 * 1.2748603825114691E-5) - q_coriolis_current_tmp * t44 * 5.0399208965540472E-5) -
      r_coriolis_current_tmp * t44 * 5.0399208965540472E-5)) + ((s_coriolis_current_tmp * t44 * -5.0399208965540472E-5 -
      t148 * t43 * 0.002428009604953112) - t149 * t43 * 0.002428009604953112)) + ((t150 * t43 * -0.002428009604953112 -
      t253 * t43 * 0.002428009604953112) - t247 * t43 * 0.002428009604953112)) + ((t185 * t43 * -0.002428009604953112 -
      t167 * t43 * 0.002428009604953112) - t165 * t43 * 0.002428009604953112)) + (((t166 * t43 * -0.002428009604953112 -
      t_coriolis_current_tmp * ct_idx_287 * 0.00654172719185474) - t141 * t43 * 1.2748603825114691E-5) - t130 * t43 *
      1.2748603825114691E-5)) + (((ct_idx_196 * t43 * -1.2748603825114691E-5 + t_coriolis_current_tmp * t44 *
      5.0399208965540472E-5) + t280 * t43 * 0.002428009604953112) + t281 * t43 * 0.002428009604953112)) + (((t279 * t43 *
      0.002428009604953112 - d131 * t33 * t44 * 2.5199604482770229E-5) + d131 * ct_idx_286 * ct_idx_287 *
      0.00654172719185474) - d132 * t33 * t44 * 2.5199604482770229E-5)) + (((d132 * ct_idx_286 * ct_idx_287 *
      0.00654172719185474 - d133 * t33 * t44 * 2.5199604482770229E-5) + d133 * ct_idx_286 * ct_idx_287 *
      0.00654172719185474) - d134 * t33 * t44 * 2.5199604482770229E-5)) + (((d134 * ct_idx_286 * ct_idx_287 *
      0.00654172719185474 - d135 * t33 * t44 * 2.5199604482770229E-5) + d135 * ct_idx_286 * ct_idx_287 *
      0.00654172719185474) - d136 * t33 * t44 * 2.5199604482770229E-5)) + (((d136 * ct_idx_286 * ct_idx_287 *
      0.00654172719185474 - d137 * t33 * t44 * 2.5199604482770229E-5) + d137 * ct_idx_286 * ct_idx_287 *
      0.00654172719185474) - d138 * t33 * t44 * 2.5199604482770229E-5)) + (((d138 * ct_idx_286 * ct_idx_287 *
      0.00654172719185474 - d139 * t33 * t44 * 2.5199604482770229E-5) + d139 * ct_idx_286 * ct_idx_287 *
      0.00654172719185474) + d141 * t33 * t44 * 2.5199604482770229E-5)) + (((d141 * ct_idx_286 * ct_idx_287 *
      -0.00654172719185474 + d142 * t33 * t44 * 2.5199604482770229E-5) - d142 * ct_idx_286 * ct_idx_287 *
                0.00654172719185474) + d143 * t33 * t44 * 2.5199604482770229E-5)) + (((d143 * ct_idx_286 * ct_idx_287 *
                -0.00654172719185474 + t92 * 0.00654172719185474) + d62 * ct_idx_285 * 0.00654172719185474) + t81 *
              0.00654172719185474)) + (((d144 * ct_idx_285 * 0.00654172719185474 + t82 * 0.00654172719185474) + d145 *
              ct_idx_284 * 0.00654172719185474) + d146 * ct_idx_285 * ct_idx_287 * 0.01308345438370948)) +
           (((u_coriolis_current_tmp * t11 * 0.00654172719185474 + v_coriolis_current_tmp * t11 * 0.00654172719185474) +
             w_coriolis_current_tmp * t11 * 0.00654172719185474) - x_coriolis_current_tmp * t11 * 0.00654172719185474))
          + (((y_coriolis_current_tmp * t11 * -0.00654172719185474 - ab_coriolis_current_tmp * t11 * 0.00654172719185474)
              - t101 * t11 * 0.00654172719185474) - t102 * t11 * 0.00654172719185474)) + (((c_coriolis_current_tmp * t11
            * -0.00654172719185474 - d_coriolis_current_tmp * t11 * 0.00654172719185474) - e_coriolis_current_tmp * t11 *
           0.00654172719185474) - f_coriolis_current_tmp * t11 * 0.00654172719185474)) + (((h_coriolis_current_tmp *
           ct_idx_287 * 0.00654172719185474 + t83 * ct_idx_287 * 0.00654172719185474) + t88 * ct_idx_287 *
          0.00654172719185474) - t92 * ct_idx_285 * 0.01308345438370948)) + (((t81 * ct_idx_285 * -0.01308345438370948 -
          t82 * ct_idx_284 * 0.01308345438370948) - h_coriolis_current_tmp * ct_idx_285 * ct_idx_287 *
         0.01308345438370948) - t83 * ct_idx_284 * ct_idx_287 * 0.01308345438370948)) + (t88 * ct_idx_283 * ct_idx_287 *
      -0.01308345438370948 + t180 * t10 * t11 * ct_idx_199 * 0.01308345438370948);
    d = d15 * t10;
    d1 = d14 * t5;
    d2 = d15 * t5;
    d3 = d16 * t5;
    d4 = d14 * t10;
    d5 = d16 * t10;
    d6 = d379 * ct_idx_290 * ct_idx_291;
    d7 = d388 * t40 * ct_idx_291;
    d8 = d179 * t40 * ct_idx_290;
    d9 = d387 * ct_idx_290 * ct_idx_291;
    d13 = d396 * t40 * ct_idx_291;
    d14 = d180 * t40 * ct_idx_290;
    c_coriolis_current_tmp = d291 * ct_idx_262;
    d_coriolis_current_tmp = d301 * ct_idx_262;
    e_coriolis_current_tmp = d181 * t33;
    f_coriolis_current_tmp = d48 * t33;
    g_coriolis_current_tmp = d240 * t33;
    h_coriolis_current_tmp = d185 * t33;
    coriolis_current[5] =
      ((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((d378 *
      8.1896778340881181E-6 + d147 * 1.637935566817624E-5) + d148 * 1.637935566817624E-5) + d149 * 1.637935566817624E-5)
      + (((d386 * 2.4705191039329719E-5 + d150 * 4.9410382078659438E-5) + d151 * 4.9410382078659438E-5) + d152 *
      4.9410382078659438E-5)) + (((d347 * 2.9411273375020609E-5 - t25 * t34 * 5.8822546750041218E-5) - t26 * t34 *
      5.8822546750041218E-5) - t27 * t34 * 5.8822546750041218E-5)) + (((t28 * t34 * 0.00011764509350008239 - ct_idx_199 *
      t44 * 0.00036217865775648968) + t25 * t44 * 0.00072435731551297948) + t26 * t44 * 0.00072435731551297948)) +
      (((t27 * t44 * 0.00072435731551297948 - t28 * t44 * 0.001448714631025959) + d282 * 3.2758711336352472E-5) + d283 *
      3.2758711336352472E-5)) + (((d284 * 3.2758711336352472E-5 + d153 * 9.8820764157318876E-5) + d154 *
      9.8820764157318876E-5) + d4 * 0.0025612921013295421)) + (((d155 * 9.8820764157318876E-5 + d *
      0.0025612921013295421) + d5 * 0.0025612921013295421) - d10 * t34 * 0.00011764509350008239)) + (((d11 * t34 *
      -0.00011764509350008239 - d12 * t34 * 0.00011764509350008239) + d10 * t44 * 0.001448714631025959) + d11 * t44 *
      0.001448714631025959)) + (((d12 * t44 * 0.001448714631025959 - d33 * 4.045998141715444E-5) - d32 * t25 *
      8.0919962834308866E-5) - d46 * 6.9994482477893542E-5)) + (((d32 * t26 * -8.0919962834308866E-5 - d37 *
      0.0001220526119108113) - d36 * t25 * 0.00024410522382162261) + d47 * 2.320290746771033E-5)) + (((d36 * t26 *
      -0.00024410522382162261 - d378 * t43 * 0.000146779850967975) + d147 * t43 * 0.00029355970193595) + d148 * t43 *
      0.00029355970193595)) + (((d149 * t43 * 0.00029355970193595 + d386 * t43 * 0.00032302241217769531) - d150 * t43 *
      0.00064604482435539061) - d151 * t43 * 0.00064604482435539061)) + (((d152 * t43 * -0.00064604482435539061 - d409 *
      2.9411273375020609E-5) + d31 * t34 * 5.8822546750041218E-5) + d34 * t34 * 5.8822546750041218E-5)) + (((d35 * t34 *
      5.8822546750041218E-5 + d312 * t44 * 0.00036217865775648968) - d31 * t44 * 0.00072435731551297948) - d34 * t44 *
      0.00072435731551297948)) + (((d35 * t44 * -0.00072435731551297948 - d1 * t6 * 0.0025841792974215629) - d2 * t6 *
      0.0025841792974215629) - d282 * t9 * 0.00016183992566861771)) + (((d3 * t6 * -0.0025841792974215629 - d1 * t11 *
      0.0011742388077438) - d2 * t11 * 0.0011742388077438) - d119 * t11 * 0.00048821044764324521)) + (((d3 * t11 *
      -0.0011742388077438 + d4 * t34 * 0.0028974292620519179) + d * t34 * 0.0028974292620519179) + d5 * t34 *
      0.0028974292620519179)) + (((d282 * t43 * 0.0005871194038719001 + d283 * t43 * 0.0005871194038719001) + d284 * t43
      * 0.0005871194038719001) - d153 * t43 * 0.001292089648710781)) + (((d154 * t43 * -0.001292089648710781 + d4 * t44 *
      0.0002352901870001649) - d155 * t43 * 0.001292089648710781) + d * t44 * 0.0002352901870001649)) + (((d5 * t44 *
      0.0002352901870001649 + d38 * t34 * 0.00011764509350008239) + d39 * t34 * 0.00011764509350008239) + d40 * t34 *
      0.00011764509350008239)) + (((d38 * t44 * -0.001448714631025959 - d39 * t44 * 0.001448714631025959) - d40 * t44 *
      0.001448714631025959) + coriolis_current_tmp * 0.0001220526119108113)) + (((d229 * t25 * 0.00024410522382162261 +
      d229 * t26 * 0.00024410522382162261) - d103 * 4.3369192817163268E-5) - d130 * 4.3369192817163268E-5)) + ((d63 *
      t25 * -8.6738385634326523E-5 - d111 * t25 * 8.6738385634326523E-5) - b_coriolis_current_tmp * 4.045998141715444E-5))
      + (((t104 * t25 * -8.0919962834308866E-5 - t104 * t26 * 8.0919962834308866E-5) - d171 * 0.000130828613222103) -
      d186 * 0.000130828613222103)) + (((d170 * t25 * -0.000261657226444206 - d182 * t25 * 0.000261657226444206) + d377 *
      0.00048821044764324521) - d248 * t11 * 0.00016183992566861771)) + (((t89 * t10 * -0.00052331445288841209 + d140 *
      t10 * t11 * 0.0001734767712686531) + t243 * 0.000130828613222103) + d58 * t25 * 0.000261657226444206)) + ((t116 *
      -4.3369192817163268E-5 - t117 * t25 * 8.6738385634326523E-5) - t121 * 0.000130828613222103)) + ((t120 * t25 *
      -0.000261657226444206 + t84 * 4.3369192817163268E-5) + t14 * t25 * 8.6738385634326523E-5)) + ((d103 * t30 *
      -4.3369192817163268E-5 - d130 * t30 * 4.3369192817163268E-5) - d231 * t40 * 4.3369192817163268E-5)) + ((d171 * t30
      * -0.000130828613222103 - d186 * t30 * 0.000130828613222103) - d232 * t40 * 0.000130828613222103)) + ((d235 * t40 *
      4.3369192817163268E-5 + d237 * t40 * 0.000130828613222103) - d219 * ct_idx_253 * 4.045998141715444E-5)) + (((d208 *
      ct_idx_290 * -4.045998141715444E-5 - d42 * ct_idx_253 * t40 * 4.045998141715444E-5) - t61 * ct_idx_253 *
      0.0001220526119108113) - d217 * ct_idx_290 * 0.0001220526119108113)) + (((d44 * ct_idx_253 * t40 *
      -0.0001220526119108113 + d33 * t40 * ct_idx_290 * 4.045998141715444E-5) - d169 * 8.1896778340881181E-6) + d37 *
      t40 * ct_idx_290 * 0.0001220526119108113)) + (((d173 * -2.4705191039329719E-5 + d6 * 8.1896778340881181E-6) + d7 *
      8.1896778340881181E-6) + d8 * 8.1896778340881181E-6)) + (((d9 * 2.4705191039329719E-5 + d13 *
      2.4705191039329719E-5) + d14 * 2.4705191039329719E-5) + d181 * t34 * 8.8233820125061836E-5)) + (((d181 * t44 *
      -0.0010865359732694689 - d48 * t34 * ct_idx_290 * ct_idx_291 * 8.8233820125061836E-5) - d240 * t34 * t40 *
      ct_idx_291 * 8.8233820125061836E-5) - d185 * t34 * t40 * ct_idx_290 * 8.8233820125061836E-5)) + (((d183 * t44 *
      0.0010865359732694689 + d184 * t44 * 0.0010865359732694689) + d187 * t44 * 0.0010865359732694689) + t91 *
      0.0025612921013295421)) + (((t68 * -0.0005871194038719001 - t127 * 0.0005871194038719001) - t103 *
      0.0005871194038719001) + t113 * 0.0025612921013295421)) + (((t114 * -0.0005871194038719001 - t94 *
      0.0005871194038719001) - t96 * 0.0005871194038719001) + t97 * 0.0025612921013295421)) + (((t98 *
      -0.0005871194038719001 - t128 * 0.0005871194038719001) - t151 * 0.0005871194038719001) + t163 *
      0.0025612921013295421)) + (((t170 * 0.0025612921013295421 + t171 * 0.0025612921013295421) + t148 *
      0.001292089648710781) + t149 * 0.001292089648710781)) + ((t150 * 0.001292089648710781 - t136 * t10 *
      0.00048821044764324521) - t146 * t10 * 0.00048821044764324521)) + ((t253 * 0.001292089648710781 + t247 *
      0.001292089648710781) + t185 * 0.001292089648710781)) + ((t181 * t10 * -0.00048821044764324521 - t168 * t10 *
      0.00048821044764324521) + t167 * 0.001292089648710781)) + (((t165 * 0.001292089648710781 + t166 *
      0.001292089648710781) - t164 * 0.0025612921013295421) - t162 * 0.0025612921013295421)) + (((t139 *
      -0.0025612921013295421 + t141 * 0.0005871194038719001) - t145 * 0.0025612921013295421) - t147 *
      0.0025612921013295421)) + (((t135 * -0.0025612921013295421 + coriolis_current_tmp_tmp * t10 * t11 *
      0.00016183992566861771) + b_coriolis_current_tmp_tmp * t10 * t11 * 0.00016183992566861771) + t130 *
      0.0005871194038719001)) + (((ct_idx_193 * -0.0025612921013295421 - ct_idx_194 * 0.0025612921013295421) -
      ct_idx_195 * 0.0025612921013295421) + n_coriolis_current_tmp_tmp * t10 * t11 * 0.00016183992566861771)) + (((t107 *
      t10 * t11 * 0.00016183992566861771 + ct_idx_196 * 0.0005871194038719001) - t115 * 0.0025612921013295421) - t280 *
      0.001292089648710781)) + (((t281 * -0.001292089648710781 - t279 * 0.001292089648710781) - d314 * t34 *
      0.0002352901870001649) + d314 * t44 * 0.0028974292620519179)) + (((f_coriolis_current_tmp_tmp * t34 *
      0.0002352901870001649 + g_coriolis_current_tmp_tmp * t34 * 0.0002352901870001649) + h_coriolis_current_tmp_tmp *
      t34 * 0.0002352901870001649) - f_coriolis_current_tmp_tmp * t44 * 0.0028974292620519179)) +
      (((g_coriolis_current_tmp_tmp * t44 * -0.0028974292620519179 - h_coriolis_current_tmp_tmp * t44 *
      0.0028974292620519179) + t243 * t30 * 0.000130828613222103) - t116 * t30 * 4.3369192817163268E-5)) + ((t121 * t30 *
      -0.000130828613222103 - d258 * t40 * 0.000130828613222103) - d259 * t40 * 0.000130828613222103)) + ((t84 * t30 *
      4.3369192817163268E-5 + d260 * t40 * 4.3369192817163268E-5) + d261 * t40 * 4.3369192817163268E-5)) + (((t77 *
      ct_idx_253 * 0.0001220526119108113 - t106 * ct_idx_253 * 4.045998141715444E-5) - t86 * ct_idx_290 *
      0.0001220526119108113) - d234 * ct_idx_253 * t40 * 0.0001220526119108113)) + ((coriolis_current_tmp * t40 *
      ct_idx_290 * -0.0001220526119108113 + t105 * ct_idx_290 * 4.045998141715444E-5) + d236 * ct_idx_253 * t40 *
      4.045998141715444E-5)) + ((b_coriolis_current_tmp * t40 * ct_idx_290 * 4.045998141715444E-5 - d156 *
      2.4705191039329719E-5) - d157 * 2.4705191039329719E-5)) + ((d158 * -2.4705191039329719E-5 + d159 *
      8.1896778340881181E-6) + d160 * 8.1896778340881181E-6)) + ((d161 * 8.1896778340881181E-6 - d162 *
      0.00064604482435539061) - d164 * 0.00064604482435539061)) + ((d165 * -0.00064604482435539061 - d166 *
      0.00029355970193595) - d167 * 0.00029355970193595)) + ((d168 * -0.00029355970193595 + d172 * 2.4705191039329719E-5)
      - d174 * 8.1896778340881181E-6)) + (((d175 * 0.00064604482435539061 - d298 * t34 * ct_idx_291 *
      0.001448714631025959) - c_coriolis_current_tmp * t34 * ct_idx_290 * 0.001448714631025959) - d_coriolis_current_tmp
      * t34 * t40 * 0.001448714631025959)) + (((d169 * t43 * 0.000146779850967975 + d177 * 0.00029355970193595) - d173 *
      t43 * 0.00032302241217769531) - d298 * ct_idx_291 * t44 * 0.00011764509350008239)) + (((c_coriolis_current_tmp *
      ct_idx_290 * t44 * -0.00011764509350008239 - d_coriolis_current_tmp * t40 * t44 * 0.00011764509350008239) +
      e_coriolis_current_tmp * t34 * 2.9411273375020609E-5) + d290 * t34 * t40 * ct_idx_290 * ct_idx_291 *
      0.001448714631025959)) + ((d6 * t43 * -0.000146779850967975 - d7 * t43 * 0.000146779850967975) - d8 * t43 *
      0.000146779850967975)) + ((d9 * t43 * 0.00032302241217769531 + d13 * t43 * 0.00032302241217769531) + d14 * t43 *
      0.00032302241217769531)) + (((e_coriolis_current_tmp * t44 * -0.00036217865775648968 + d290 * t40 * ct_idx_290 *
      ct_idx_291 * t44 * 0.00011764509350008239) - f_coriolis_current_tmp * t34 * ct_idx_290 * ct_idx_291 *
      2.9411273375020609E-5) - g_coriolis_current_tmp * t34 * t40 * ct_idx_291 * 2.9411273375020609E-5)) +
      (((h_coriolis_current_tmp * t34 * t40 * ct_idx_290 * -2.9411273375020609E-5 + f_coriolis_current_tmp * ct_idx_290 *
      ct_idx_291 * t44 * 0.00036217865775648968) + g_coriolis_current_tmp * t40 * ct_idx_291 * t44 *
      0.00036217865775648968) + h_coriolis_current_tmp * t40 * ct_idx_290 * t44 * 0.00036217865775648968)) + ((t264 *
      -9.8820764157318876E-5 - t260 * 9.8820764157318876E-5) - t215 * 9.8820764157318876E-5)) + ((t216 *
      3.2758711336352472E-5 + t217 * 3.2758711336352472E-5) + t218 * 3.2758711336352472E-5)) +
      ((i_coriolis_current_tmp_tmp * t10 * 0.0025841792974215629 + j_coriolis_current_tmp_tmp * t10 *
      0.0025841792974215629) + l_coriolis_current_tmp_tmp * t10 * 0.0025841792974215629)) + (((t219 *
      9.8820764157318876E-5 + t220 * 9.8820764157318876E-5) + t222 * 9.8820764157318876E-5) + t209 *
      9.8820764157318876E-5)) + (((t210 * 9.8820764157318876E-5 + t211 * 9.8820764157318876E-5) + t208 *
      9.8820764157318876E-5) + t207 * 9.8820764157318876E-5)) + (((t206 * 9.8820764157318876E-5 + d254 * t10 * t11 *
      0.0011742388077438) + d255 * t10 * t11 * 0.0011742388077438) + d256 * t10 * t11 * 0.0011742388077438)) + ((t184 *
      -3.2758711336352472E-5 - t187 * 3.2758711336352472E-5) - t190 * 3.2758711336352472E-5)) + ((t193 *
      -3.2758711336352472E-5 - t194 * 3.2758711336352472E-5) - t195 * 3.2758711336352472E-5)) + ((t196 *
      -3.2758711336352472E-5 - t197 * 3.2758711336352472E-5) - t204 * 3.2758711336352472E-5)) +
      ((m_coriolis_current_tmp_tmp * t10 * -0.0025841792974215629 - d257 * t10 * t11 * 0.0011742388077438) - t91 * t34 *
      0.0028974292620519179)) + (((t68 * t33 * 0.0005871194038719001 + t127 * t33 * 0.0005871194038719001) + t103 * t33 *
      0.0005871194038719001) - t113 * t34 * 0.0028974292620519179)) + (((t114 * t33 * 0.0005871194038719001 + t94 * t33 *
      0.0005871194038719001) + t96 * t33 * 0.0005871194038719001) - t97 * t34 * 0.0028974292620519179)) + (((t98 * t33 *
      0.0005871194038719001 + t128 * t33 * 0.0005871194038719001) + t151 * t33 * 0.0005871194038719001) + t163 * t34 *
      0.0028974292620519179)) + ((t170 * t34 * 0.0028974292620519179 + t171 * t34 * 0.0028974292620519179) - t148 * t33 *
      0.001292089648710781)) + ((t149 * t33 * -0.001292089648710781 - t150 * t33 * 0.001292089648710781) - t253 * t33 *
      0.001292089648710781)) + ((t247 * t33 * -0.001292089648710781 - t185 * t33 * 0.001292089648710781) - t167 * t33 *
      0.001292089648710781)) + ((t165 * t33 * -0.001292089648710781 - t166 * t33 * 0.001292089648710781) - t91 * t44 *
      0.0002352901870001649)) + (((t164 * t34 * 0.0028974292620519179 + t162 * t34 * 0.0028974292620519179) + t139 * t34
      * 0.0028974292620519179) - t141 * t33 * 0.0005871194038719001)) + (((t113 * t44 * -0.0002352901870001649 + t145 *
      t34 * 0.0028974292620519179) + t147 * t34 * 0.0028974292620519179) + t135 * t34 * 0.0028974292620519179)) +
                 (((t130 * t33 * -0.0005871194038719001 - t97 * t44 * 0.0002352901870001649) + ct_idx_193 * t34 *
                   0.0028974292620519179) + ct_idx_194 * t34 * 0.0028974292620519179)) + (((ct_idx_195 * t34 *
      0.0028974292620519179 - ct_idx_196 * t33 * 0.0005871194038719001) + t163 * t44 * 0.0002352901870001649) + t170 *
      t44 * 0.0002352901870001649)) + ((t171 * t44 * 0.0002352901870001649 - t115 * t34 * 0.0028974292620519179) + t280 *
                t33 * 0.001292089648710781)) + (((t281 * t33 * 0.001292089648710781 + t279 * t33 * 0.001292089648710781)
                + t164 * t44 * 0.0002352901870001649) + t162 * t44 * 0.0002352901870001649)) + (((t139 * t44 *
                0.0002352901870001649 + t145 * t44 * 0.0002352901870001649) + t147 * t44 * 0.0002352901870001649) + t135
              * t44 * 0.0002352901870001649)) + (((ct_idx_193 * t44 * 0.0002352901870001649 + ct_idx_194 * t44 *
               0.0002352901870001649) + ct_idx_195 * t44 * 0.0002352901870001649) - t115 * t44 * 0.0002352901870001649))
           + (((d131 * t34 * t43 * -0.00011764509350008239 - d132 * t34 * t43 * 0.00011764509350008239) - d133 * t34 *
               t43 * 0.00011764509350008239) - d134 * t34 * t43 * 0.00011764509350008239)) + (((d135 * t34 * t43 *
             -0.00011764509350008239 - d136 * t34 * t43 * 0.00011764509350008239) - d137 * t34 * t43 *
            0.00011764509350008239) - d138 * t34 * t43 * 0.00011764509350008239)) + (((d139 * t34 * t43 *
            -0.00011764509350008239 + d131 * t43 * t44 * 0.001448714631025959) + d132 * t43 * t44 * 0.001448714631025959)
          + d133 * t43 * t44 * 0.001448714631025959)) + (((d141 * t34 * t43 * 0.00011764509350008239 + d134 * t43 * t44 *
           0.001448714631025959) + d135 * t43 * t44 * 0.001448714631025959) + d136 * t43 * t44 * 0.001448714631025959))
       + (((d142 * t34 * t43 * 0.00011764509350008239 + d137 * t43 * t44 * 0.001448714631025959) + d138 * t43 * t44 *
           0.001448714631025959) + d139 * t43 * t44 * 0.001448714631025959)) + (((d143 * t34 * t43 *
      0.00011764509350008239 - d141 * t43 * t44 * 0.001448714631025959) - d142 * t43 * t44 * 0.001448714631025959) -
      d143 * t43 * t44 * 0.001448714631025959);
}
}  // namespace ur10_inverse_dynamics_solver

//
// File trailer for getCoriolisCurrents.cpp
//
// [EOF]
//
