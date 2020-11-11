#include <Arduino.h>

/******************************************************** Symbols ********************************************************/

bool matrix_space[7][5] = {         // space
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   }};

bool matrix_exclamation[7][5] = {   // !
{   0, 0, 1, 0, 0   },
{   0, 0, 1, 0, 0   },
{   0, 0, 1, 0, 0   },
{   0, 0, 1, 0, 0   },
{   0, 0, 1, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 1, 0, 0   }};

bool matrix_quote[7][5] = {         // "
{   0, 1, 0, 1, 0   },
{   0, 1, 0, 1, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   }};

bool matrix_hash[7][5] = {          // #
{   0, 0, 0, 0, 0   },
{   0, 1, 0, 1, 0   },
{   1, 1, 1, 1, 1   },
{   0, 1, 0, 1, 0   },
{   1, 1, 1, 1, 1   },
{   0, 1, 0, 1, 0   },
{   0, 0, 0, 0, 0   }};

bool matrix_dollar[7][5] = {        // $ = degrees
{   0, 0, 1, 0, 0   },
{   0, 1, 0, 1, 0   },
{   0, 0, 1, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   }};

bool matrix_percent[7][5] = {       // %
{   0, 0, 0, 0, 0   },
{   1, 0, 0, 0, 1   },
{   0, 0, 0, 1, 0   },
{   0, 0, 1, 0, 0   },
{   0, 1, 0, 0, 0   },
{   1, 0, 0, 0, 1   },
{   0, 0, 0, 0, 0   }};

bool matrix_ampersand[7][5] = {     // &
{   0, 1, 1, 1, 0   },
{   1, 0, 0, 0, 0   },
{   0, 1, 0, 0, 0   },
{   1, 0, 1, 0, 1   },
{   1, 0, 0, 1, 0   },
{   1, 0, 1, 0, 1   },
{   0, 1, 0, 0, 0   }};

bool matrix_invcomma[7][5] = {     // '
{   0, 0, 1, 0, 0   },
{   0, 0, 1, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   }};

bool matrix_openbracket[7][5] = {       // (
{   0, 0, 1, 0, 0   },
{   0, 1, 0, 0, 0   },
{   0, 1, 0, 0, 0   },
{   0, 1, 0, 0, 0   },
{   0, 1, 0, 0, 0   },
{   0, 1, 0, 0, 0   },
{   0, 0, 1, 0, 0   }};

bool matrix_closebracket[7][5] = {       // )
{   0, 0, 1, 0, 0   },
{   0, 0, 0, 1, 0   },
{   0, 0, 0, 1, 0   },
{   0, 0, 0, 1, 0   },
{   0, 0, 0, 1, 0   },
{   0, 0, 0, 1, 0   },
{   0, 0, 1, 0, 0   }};

bool matrix_asterisk[7][5] = {       // *
{   0, 1, 0, 1, 0   },
{   0, 0, 1, 0, 0   },
{   0, 1, 0, 1, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   }};

bool matrix_plus[7][5] = {       // +
{   0, 0, 0, 0, 0   },
{   0, 0, 1, 0, 0   },
{   0, 0, 1, 0, 0   },
{   1, 1, 1, 1, 1   },
{   0, 0, 1, 0, 0   },
{   0, 0, 1, 0, 0   },
{   0, 0, 0, 0, 0   }};

bool matrix_comma[7][5] = {       // ,
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 1, 0, 0   },
{   0, 1, 0, 0, 0   }};

bool matrix_hyphen[7][5] = {       // -
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 1, 1, 1, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   }};

bool matrix_point[7][5] = {       // .
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 1, 0, 0   }};

bool matrix_forwardslash[7][5] = {       // /
{   0, 0, 0, 0, 1   },
{   0, 0, 0, 1, 0   },
{   0, 0, 1, 1, 0   },
{   0, 0, 1, 0, 0   },
{   0, 1, 1, 0, 0   },
{   0, 1, 0, 0, 0   },
{   1, 0, 0, 0, 0   }};

bool matrix_colon[7][5] = {       // :
{   0, 0, 0, 0, 0   },
{   0, 0, 1, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 1, 0, 0   },
{   0, 0, 0, 0, 0   }};

bool matrix_semicolon[7][5] = {       // ;
{   0, 0, 0, 0, 0   },
{   0, 0, 1, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 1, 0, 0   },
{   0, 1, 0, 0, 0   }};

bool matrix_lessthan[7][5] = {       // <
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 1, 1   },
{   0, 1, 1, 0, 0   },
{   1, 0, 0, 0, 0   },
{   0, 1, 1, 0, 0   },
{   0, 0, 0, 1, 1   },
{   0, 0, 0, 0, 0   }};

bool matrix_equals[7][5] = {       // /
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 1, 1, 1, 0   },
{   0, 0, 0, 0, 0   },
{   0, 1, 1, 1, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   }};

bool matrix_morethan[7][5] = {       // >
{   0, 0, 0, 0, 0   },
{   1, 1, 0, 0, 0   },
{   0, 0, 1, 1, 0   },
{   0, 0, 0, 0, 1   },
{   0, 0, 1, 1, 0   },
{   1, 1, 0, 0, 0   },
{   0, 0, 0, 0, 0   }};

bool matrix_question[7][5] = {       // ?
{   0, 1, 1, 1, 0   },
{   1, 0, 0, 0, 1   },
{   0, 0, 0, 0, 1   },
{   0, 0, 1, 1, 0   },
{   0, 0, 1, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 1, 0, 0   }};

bool matrix_at[7][5] = {       // @
{   1, 1, 1, 1, 1   },
{   1, 0, 0, 0, 1   },
{   1, 0, 1, 1, 1   },
{   1, 0, 1, 0, 1   },
{   1, 0, 1, 1, 1   },
{   1, 0, 0, 0, 0   },
{   1, 1, 1, 1, 1   }};

/******************************************************** Numbers ********************************************************/

bool matrix_0[7][5] = {       // 0
{   0, 1, 1, 1, 0   },
{   1, 1, 0, 1, 1   },
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   },
{   1, 1, 0, 1, 1   },
{   0, 1, 1, 1, 0   }};

bool matrix_1[7][5] = {       // 1
{   0, 0, 1, 0, 0   },
{   0, 1, 1, 0, 0   },
{   0, 0, 1, 0, 0   },
{   0, 0, 1, 0, 0   },
{   0, 0, 1, 0, 0   },
{   0, 0, 1, 0, 0   },
{   0, 1, 1, 1, 0   }};

bool matrix_2[7][5] = {       // 2
{   0, 1, 1, 1, 0   },
{   1, 0, 0, 0, 1   },
{   0, 0, 0, 0, 1   },
{   0, 0, 0, 1, 1   },
{   0, 1, 1, 0, 0   },
{   1, 1, 0, 0, 0   },
{   1, 1, 1, 1, 1   }};

bool matrix_3[7][5] = {       // 3
{   0, 1, 1, 1, 0   },
{   1, 0, 0, 0, 1   },
{   0, 0, 0, 0, 1   },
{   0, 1, 1, 1, 0   },
{   0, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   },
{   0, 1, 1, 1, 0   }};

bool matrix_4[7][5] = {       // 4
{   0, 0, 0, 1, 0   },
{   0, 0, 1, 1, 0   },
{   0, 1, 1, 1, 0   },
{   0, 1, 0, 1, 0   },
{   1, 0, 0, 1, 0   },
{   1, 1, 1, 1, 1   },
{   0, 0, 0, 1, 0   }};

bool matrix_5[7][5] = {       // 5
{   1, 1, 1, 1, 1   },
{   1, 0, 0, 0, 0   },
{   1, 0, 1, 1, 0   },
{   1, 1, 0, 0, 1   },
{   0, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   },
{   0, 1, 1, 1, 0   }};

bool matrix_6[7][5] = {       // 6
{   0, 1, 1, 1, 0   },
{   1, 0, 0, 0, 0   },
{   1, 0, 0, 0, 0   },
{   1, 1, 1, 1, 0   },
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   },
{   0, 1, 1, 1, 0   }};

bool matrix_7[7][5] = {       // 7
{   1, 1, 1, 1, 1   },
{   0, 0, 0, 0, 1   },
{   0, 0, 0, 1, 0   },
{   0, 0, 1, 1, 0   },
{   0, 1, 1, 0, 0   },
{   1, 1, 0, 0, 0   },
{   1, 0, 0, 0, 0   }};

bool matrix_8[7][5] = {       // 8
{   0, 1, 1, 1, 0   },
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   },
{   0, 1, 1, 1, 0   },
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   },
{   0, 1, 1, 1, 0   }};

bool matrix_9[7][5] = {       // 9
{   0, 1, 1, 1, 0   },
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   },
{   0, 1, 1, 1, 0   },
{   0, 0, 0, 0, 1   },
{   0, 0, 0, 0, 1   },
{   0, 1, 1, 1, 0   }};

/******************************************************** Letters ********************************************************/

bool matrix_A[7][5] = {       // A
{   0, 1, 1, 1, 0   },
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   },
{   1, 1, 1, 1, 1   },
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   }};

bool matrix_B[7][5] = {       // B
{   1, 1, 1, 1, 0   },
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   },
{   1, 1, 1, 1, 0   },
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   },
{   1, 1, 1, 1, 0   }};

bool matrix_C[7][5] = {       // C
{   0, 1, 1, 1, 0   },
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 0   },
{   1, 0, 0, 0, 0   },
{   1, 0, 0, 0, 0   },
{   1, 0, 0, 0, 1   },
{   0, 1, 1, 1, 0   }};

bool matrix_D[7][5] = {       // D
{   1, 1, 1, 1, 0   },
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   },
{   1, 1, 1, 1, 0   }};

bool matrix_E[7][5] = {       // E
{   1, 1, 1, 1, 1   },
{   1, 0, 0, 0, 0   },
{   1, 0, 0, 0, 0   },
{   1, 1, 1, 1, 0   },
{   1, 0, 0, 0, 0   },
{   1, 0, 0, 0, 0   },
{   1, 1, 1, 1, 1   }};

bool matrix_F[7][5] = {       // F
{   1, 1, 1, 1, 1   },
{   1, 0, 0, 0, 0   },
{   1, 0, 0, 0, 0   },
{   1, 1, 1, 1, 0   },
{   1, 0, 0, 0, 0   },
{   1, 0, 0, 0, 0   },
{   1, 0, 0, 0, 0   }};

bool matrix_G[7][5] = {       // G
{   0, 1, 1, 1, 0   },
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 0   },
{   1, 0, 1, 1, 1   },
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   },
{   0, 1, 1, 1, 1   }};

bool matrix_H[7][5] = {       // H
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   },
{   1, 1, 1, 1, 1   },
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   }};

bool matrix_I[7][5] = {       // I
{   0, 1, 1, 1, 0   },
{   0, 0, 1, 0, 0   },
{   0, 0, 1, 0, 0   },
{   0, 0, 1, 0, 0   },
{   0, 0, 1, 0, 0   },
{   0, 0, 1, 0, 0   },
{   0, 1, 1, 1, 0   }};

bool matrix_J[7][5] = {       // J
{   1, 1, 1, 1, 1   },
{   0, 0, 0, 0, 1   },
{   0, 0, 0, 0, 1   },
{   0, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   },
{   1, 1, 0, 1, 1   },
{   0, 1, 1, 1, 0   }};

bool matrix_K[7][5] = {       // K
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 1, 0   },
{   1, 0, 1, 0, 0   },
{   1, 1, 0, 0, 0   },
{   1, 0, 1, 0, 0   },
{   1, 0, 0, 1, 0   },
{   1, 0, 0, 0, 1   }};

bool matrix_L[7][5] = {       // L
{   1, 0, 0, 0, 0   },
{   1, 0, 0, 0, 0   },
{   1, 0, 0, 0, 0   },
{   1, 0, 0, 0, 0   },
{   1, 0, 0, 0, 0   },
{   1, 0, 0, 0, 0   },
{   1, 1, 1, 1, 1   }};

bool matrix_M[7][5] = {       // M
{   1, 0, 0, 0, 1   },
{   1, 1, 0, 1, 1   },
{   1, 0, 1, 0, 1   },
{   1, 0, 1, 0, 1   },
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   }};

bool matrix_N[7][5] = {       // N
{   1, 0, 0, 0, 1   },
{   1, 1, 0, 0, 1   },
{   1, 1, 1, 0, 1   },
{   1, 0, 1, 0, 1   },
{   1, 0, 1, 1, 1   },
{   1, 0, 0, 1, 1   },
{   1, 0, 0, 0, 1   }};

bool matrix_O[7][5] = {       // O
{   0, 1, 1, 1, 0   },
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   },
{   0, 1, 1, 1, 0   }};

bool matrix_P[7][5] = {       // P
{   1, 1, 1, 1, 0   },
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   },
{   1, 1, 1, 1, 0   },
{   1, 0, 0, 0, 0   },
{   1, 0, 0, 0, 0   },
{   1, 0, 0, 0, 0   }};

bool matrix_Q[7][5] = {       // Q
{   0, 1, 1, 1, 0   },
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   },
{   1, 0, 1, 0, 1   },
{   0, 1, 1, 1, 0   },
{   0, 0, 0, 1, 1   }};

bool matrix_R[7][5] = {       // R
{   1, 1, 1, 1, 0   },
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   },
{   1, 1, 1, 1, 0   },
{   1, 0, 1, 0, 0   },
{   1, 0, 0, 1, 0   },
{   1, 0, 0, 0, 1   }};

bool matrix_S[7][5] = {       // S
{   0, 1, 1, 1, 1   },
{   1, 0, 0, 0, 0   },
{   1, 0, 0, 0, 0   },
{   0, 1, 1, 1, 0   },
{   0, 0, 0, 0, 1   },
{   0, 0, 0, 0, 1   },
{   1, 1, 1, 1, 0   }};

bool matrix_T[7][5] = {       // T
{   1, 1, 1, 1, 1   },
{   0, 0, 1, 0, 0   },
{   0, 0, 1, 0, 0   },
{   0, 0, 1, 0, 0   },
{   0, 0, 1, 0, 0   },
{   0, 0, 1, 0, 0   },
{   0, 0, 1, 0, 0   }};

bool matrix_U[7][5] = {       // U
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   },
{   0, 1, 1, 1, 0   }};

bool matrix_V[7][5] = {       // V
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   },
{   1, 1, 0, 1, 1   },
{   0, 1, 0, 1, 0   },
{   0, 1, 1, 1, 0   },
{   0, 0, 1, 0, 0   }};

bool matrix_W[7][5] = {       // W
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   },
{   1, 0, 1, 0, 1   },
{   1, 0, 1, 0, 1   },
{   0, 1, 0, 1, 0   },
{   0, 1, 0, 1, 0   }};

bool matrix_X[7][5] = {       // X
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   },
{   0, 1, 0, 1, 0   },
{   0, 0, 1, 0, 0   },
{   0, 1, 0, 1, 0   },
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   }};

bool matrix_Y[7][5] = {       // Y
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 0, 1   },
{   0, 1, 0, 1, 0   },
{   0, 1, 0, 1, 0   },
{   0, 0, 1, 0, 0   },
{   0, 0, 1, 0, 0   },
{   0, 0, 1, 0, 0   }};

bool matrix_Z[7][5] = {       // Z
{   1, 1, 1, 1, 1   },
{   0, 0, 0, 0, 1   },
{   0, 0, 0, 1, 0   },
{   0, 0, 1, 0, 0   },
{   0, 1, 0, 0, 0   },
{   1, 0, 0, 0, 0   },
{   1, 1, 1, 1, 1   }};

bool matrix_a[7][5] = {       // a
{   0, 0, 0, 0, 0   },
{   0, 1, 1, 1, 0   },
{   0, 0, 0, 0, 1   },
{   0, 1, 1, 1, 1   },
{   1, 0, 0, 0, 1   },
{   1, 0, 0, 1, 1   },
{   0, 1, 1, 1, 1   }};

bool matrix_b[7][5] = {       // b
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 1, 0, 0, 0   },
{   0, 1, 0, 0, 0   },
{   0, 1, 1, 0, 0   },
{   0, 1, 0, 1, 0   },
{   0, 1, 1, 0, 0   }};

bool matrix_c[7][5] = {       // c
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 1, 1, 0   },
{   0, 1, 0, 0, 0   },
{   0, 1, 0, 0, 0   },
{   0, 1, 0, 0, 0   },
{   0, 0, 1, 1, 0   }};

bool matrix_d[7][5] = {       // d
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 1, 0   },
{   0, 0, 0, 1, 0   },
{   0, 0, 1, 1, 0   },
{   0, 1, 0, 1, 0   },
{   0, 0, 1, 1, 0   }};

bool matrix_e[7][5] = {       // e
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 1, 1, 0   },
{   0, 1, 0, 1, 0   },
{   0, 1, 1, 1, 0   },
{   0, 1, 0, 0, 0   },
{   0, 0, 1, 1, 0   }};

bool matrix_f[7][5] = {       // f
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 1, 1, 0   },
{   0, 0, 1, 0, 0   },
{   0, 1, 1, 1, 0   },
{   0, 0, 1, 0, 0   },
{   0, 1, 1, 0, 0   }};

bool matrix_g[7][5] = {       // g
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 1, 1, 0, 0   },
{   0, 1, 0, 1, 0   },
{   0, 1, 1, 1, 0   },
{   0, 0, 0, 1, 0   },
{   0, 1, 1, 0, 0   }};

bool matrix_h[7][5] = {       // h
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 1, 0, 0, 0   },
{   0, 1, 0, 0, 0   },
{   0, 1, 1, 0, 0   },
{   0, 1, 0, 1, 0   },
{   0, 1, 0, 1, 0   }};

bool matrix_i[7][5] = {       // i
{   0, 0, 0, 0, 0   },
{   0, 0, 1, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 1, 1, 0, 0   },
{   0, 0, 1, 0, 0   },
{   0, 0, 1, 0, 0   },
{   0, 1, 1, 1, 0   }};

bool matrix_j[7][5] = {       // j
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 1, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 1, 1, 0   },
{   0, 0, 0, 1, 0   },
{   0, 1, 0, 1, 0   },
{   0, 1, 1, 0, 0   }};

bool matrix_k[7][5] = {       // k
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 1, 0, 0, 0   },
{   0, 1, 0, 1, 0   },
{   0, 1, 1, 0, 0   },
{   0, 1, 0, 1, 0   },
{   0, 1, 0, 0, 0   }};

bool matrix_l[7][5] = {       // l
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 1, 1, 0, 0   },
{   0, 0, 1, 0, 0   },
{   0, 0, 1, 0, 0   },
{   0, 0, 1, 0, 0   },
{   0, 1, 1, 1, 0   }};

bool matrix_m[7][5] = {       // m
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   1, 0, 0, 0, 0   },
{   1, 1, 1, 1, 0   },
{   1, 0, 1, 0, 1   },
{   1, 0, 1, 0, 1   }};

bool matrix_n[7][5] = {       // n
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 1, 0, 0, 0   },
{   0, 1, 1, 0, 0   },
{   0, 1, 0, 1, 0   },
{   0, 1, 0, 1, 0   }};

bool matrix_o[7][5] = {       // o
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 1, 0, 0   },
{   0, 1, 0, 1, 0   },
{   0, 1, 0, 1, 0   },
{   0, 0, 1, 0, 0   }};

bool matrix_p[7][5] = {       // p
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 1, 1, 0, 0   },
{   0, 1, 0, 1, 0   },
{   0, 1, 1, 1, 0   },
{   0, 1, 0, 0, 0   },
{   0, 1, 0, 0, 0   }};

bool matrix_q[7][5] = {       // q
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 1, 1, 0   },
{   0, 1, 0, 1, 0   },
{   0, 1, 1, 1, 0   },
{   0, 0, 0, 1, 0   },
{   0, 0, 0, 1, 0   }};

bool matrix_r[7][5] = {       // r
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 1, 0, 0, 0   },
{   0, 1, 1, 1, 0   },
{   0, 1, 0, 1, 0   },
{   0, 1, 0, 0, 0   },
{   0, 1, 0, 0, 0   }};

bool matrix_s[7][5] = {       // s
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 1, 1, 1, 0   },
{   0, 1, 0, 0, 0   },
{   0, 1, 1, 1, 0   },
{   0, 0, 0, 1, 0   },
{   0, 1, 1, 1, 0   }};

bool matrix_t[7][5] = {       // t
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 1, 0, 0, 0   },
{   0, 1, 1, 0, 0   },
{   0, 1, 0, 0, 0   },
{   0, 1, 0, 1, 0   },
{   0, 0, 1, 0, 0   }};

bool matrix_u[7][5] = {       // u
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 1, 0, 1, 0   },
{   0, 1, 0, 1, 0   },
{   0, 1, 1, 1, 0   },
{   0, 0, 0, 0, 0   }};

bool matrix_v[7][5] = {       // v
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 1, 0, 1, 0   },
{   0, 1, 0, 1, 0   },
{   0, 0, 1, 0, 0   },
{   0, 0, 0, 0, 0   }};

bool matrix_w[7][5] = {       // w
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   1, 0, 0, 0, 1   },
{   1, 0, 1, 0, 1   },
{   0, 1, 0, 1, 0   }};

bool matrix_x[7][5] = {       // x
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 1, 0, 1, 0   },
{   0, 0, 1, 0, 0   },
{   0, 1, 0, 1, 0   },
{   0, 0, 0, 0, 0   }};

bool matrix_y[7][5] = {       // y
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 1, 0, 1, 0   },
{   0, 1, 0, 1, 0   },
{   0, 0, 1, 0, 0   },
{   0, 1, 0, 0, 0   },
{   0, 0, 0, 0, 0   }};

bool matrix_z[7][5] = {       // z
{   0, 0, 0, 0, 0   },
{   0, 0, 0, 0, 0   },
{   0, 1, 1, 1, 0   },
{   0, 0, 0, 1, 0   },
{   0, 0, 1, 0, 0   },
{   0, 1, 0, 0, 0   },
{   0, 1, 1, 1, 0   }};

void fillmatrix(char value)
{
    extern int payload[12];
    bool payloadbits[96] = {0};

    switch (value)
    {
    case ' ':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_space[row][column];
            }
        }
    break;
    case '!':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_exclamation[row][column];
            }
        }
    break;
    case '"':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_quote[row][column];
            }
        }
    break;
    case '#':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_hash[row][column];
            }
        }
    break;
    case '$':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_dollar[row][column];
            }
        }
    break;
    case '%':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_percent[row][column];
            }
        }
    break;
    case '&':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_ampersand[row][column];
            }
        }
    break;
    case '\'':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_invcomma[row][column];
            }
        }
    break;
    case '(':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_openbracket[row][column];
            }
        }
    break;
    case ')':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_closebracket[row][column];
            }
        }
    break;
    case '*':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_asterisk[row][column];
            }
        }
    break;
    case '+':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_plus[row][column];
            }
        }
    break;
    case ',':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_comma[row][column];
            }
        }
    break;
    case '-':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_hyphen[row][column];
            }
        }
    break;
    case '.':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_point[row][column];
            }
        }
    break;
    case '/':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_forwardslash[row][column];
            }
        }
    break;
    case ':':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_colon[row][column];
            }
        }
    break;
    case ';':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_semicolon[row][column];
            }
        }
    break;
    case '<':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_lessthan[row][column];
            }
        }
    break;
    case '=':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_equals[row][column];
            }
        }
    break;
    case '>':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_morethan[row][column];
            }
        }
    break;
    case '?':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_question[row][column];
            }
        }
    break;
    case '@':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_at[row][column];
            }
        }
    break;
    case '0':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_0[row][column];
            }
        }
    break;
    case '1':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_1[row][column];
            }
        }
    break;
    case '2':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_2[row][column];
            }
        }
    break;
    case '3':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_3[row][column];
            }
        }
    break;
    case '4':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_4[row][column];
            }
        }
    break;
    case '5':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_5[row][column];
            }
        }
    break;
    case '6':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_6[row][column];
            }
        }
    break;
    case '7':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_7[row][column];
            }
        }
    break;
    case '8':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_8[row][column];
            }
        }
    break;
    case '9':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_9[row][column];
            }
        }
    break;
    case 'A':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_A[row][column];
            }
        }
    break;
    case 'B':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_B[row][column];
            }
        }
    break;
    case 'C':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_C[row][column];
            }
        }
    break;
    case 'D':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_D[row][column];
            }
        }
    break;
    case 'E':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_E[row][column];
            }
        }
    break;
    case 'F':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_F[row][column];
            }
        }
    break;
    case 'G':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_G[row][column];
            }
        }
    break;
    case 'H':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_H[row][column];
            }
        }
    break;
    case 'I':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_I[row][column];
            }
        }
    break;
    case 'J':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_J[row][column];
            }
        }
    break;
    case 'K':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_K[row][column];
            }
        }
    break;
    case 'L':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_L[row][column];
            }
        }
    break;
    case 'M':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_M[row][column];
            }
        }
    break;
    case 'N':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_N[row][column];
            }
        }
    break;
    case 'O':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_O[row][column];
            }
        }
    break;
    case 'P':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_P[row][column];
            }
        }
    break;
    case 'Q':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_Q[row][column];
            }
        }
    break;
    case 'R':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_R[row][column];
            }
        }
    break;
    case 'S':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_S[row][column];
            }
        }
    break;
    case 'T':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_T[row][column];
            }
        }
    break;
    case 'U':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_U[row][column];
            }
        }
    break;
    case 'V':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_V[row][column];
            }
        }
    break;
    case 'W':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_W[row][column];
            }
        }
    break;
    case 'X':
        for (int column = 0; column < 5; ++column)
        {
            for (int row = 0; row < 7; ++row)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_X[row][column];
            }
        }
    break;
    case 'Y':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_Y[row][column];
            }
        }
    break;
    case 'Z':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_Z[row][column];
            }
        }
    break;
    case 'a':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_a[row][column];
            }
        }
    break;
    case 'b':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_b[row][column];
            }
        }
    break;
    case 'c':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_c[row][column];
            }
        }
    break;
    case 'd':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_d[row][column];
            }
        }
    break;
    case 'e':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_e[row][column];
            }
        }
    break;
    case 'f':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_f[row][column];
            }
        }
    break;
    case 'g':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_g[row][column];
            }
        }
    break;
    case 'h':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_h[row][column];
            }
        }
    break;
    case 'i':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_i[row][column];
            }
        }
    break;
    case 'j':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_j[row][column];
            }
        }
    break;
    case 'k':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_k[row][column];
            }
        }
    break;
    case 'l':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_l[row][column];
            }
        }
    break;
    case 'm':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_m[row][column];
            }
        }
    break;
    case 'n':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_n[row][column];
            }
        }
    break;
    case 'o':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_o[row][column];
            }
        }
    break;
    case 'p':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_p[row][column];
            }
        }
    break;
    case 'q':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_q[row][column];
            }
        }
    break;
    case 'r':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_r[row][column];
            }
        }
    break;
    case 's':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_s[row][column];
            }
        }
    break;
    case 't':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_t[row][column];
            }
        }
    break;
    case 'u':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_u[row][column];
            }
        }
    break;
    case 'v':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_v[row][column];
            }
        }
    break;
    case 'w':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_w[row][column];
            }
        }
    break;
    case 'x':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_x[row][column];
            }
        }
    break;
    case 'y':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_y[row][column];
            }
        }
    break;
    case 'z':
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_z[row][column];
            }
        }
    break;
    
    default:        // Unknown character, show ?
        for (int row = 0; row < 7; ++row)
        {
            for (int column = 0; column < 5; ++column)
            {
                payloadbits[59 + (column + (5 * row))] = matrix_question[row][column];
            }
        }
    break;
    }

    for(int i = 56; i < 95; ++i)
    {
        payload[(i / 8)-1] |= (payloadbits[i] << (7 - (i % 8)));
    }
}