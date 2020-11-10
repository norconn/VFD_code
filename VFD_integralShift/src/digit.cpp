#include <Arduino.h>

void filldigit(int digit, int value, bool dots[6], bool commas[6], bool colons[2][2])
{
    extern int payload[12];
    bool payloadbits[96] = {0};

    for(int i = 0; i < 11; ++i)
        payload[i] = 0;

    switch (digit)
    {
    case 0:
        if(dots[0])
            payloadbits[87] = 1;
        if(commas[0])
            payloadbits[90] = 1;
        switch (value)
        {
        case 0:
            payloadbits[61] = 1;    // a
            payloadbits[64] = 1;    // b
            payloadbits[76] = 1;    // c
            payloadbits[84] = 1;    // d
            payloadbits[81] = 1;    // e
            payloadbits[69] = 1;    // f
            break;
        case 1:
            payloadbits[64] = 1;    // b
            payloadbits[76] = 1;    // c
            break;
        case 2:
            payloadbits[61] = 1;    // a
            payloadbits[64] = 1;    // b
            payloadbits[84] = 1;    // d
            payloadbits[81] = 1;    // e
            payloadbits[72] = 1;    // g
            break;
        case 3:
            payloadbits[61] = 1;    // a
            payloadbits[64] = 1;    // b
            payloadbits[76] = 1;    // c
            payloadbits[84] = 1;    // d
            payloadbits[72] = 1;    // g
            break;
        case 4:
            payloadbits[64] = 1;    // b
            payloadbits[76] = 1;    // c
            payloadbits[69] = 1;    // f
            payloadbits[72] = 1;    // g
            break;
        case 5:
            payloadbits[61] = 1;    // a
            payloadbits[76] = 1;    // c
            payloadbits[84] = 1;    // d
            payloadbits[69] = 1;    // f
            payloadbits[72] = 1;    // g
            break;
        case 6:
            payloadbits[61] = 1;    // a
            payloadbits[76] = 1;    // c
            payloadbits[84] = 1;    // d
            payloadbits[81] = 1;    // e
            payloadbits[69] = 1;    // f
            payloadbits[72] = 1;    // g
            break;
        case 7:
            payloadbits[61] = 1;    // a
            payloadbits[64] = 1;    // b
            payloadbits[76] = 1;    // c
            break;
        case 8:
            payloadbits[61] = 1;    // a
            payloadbits[64] = 1;    // b
            payloadbits[76] = 1;    // c
            payloadbits[84] = 1;    // d
            payloadbits[81] = 1;    // e
            payloadbits[69] = 1;    // f
            payloadbits[72] = 1;    // g
            break;
        case 9:
            payloadbits[61] = 1;    // a
            payloadbits[64] = 1;    // b
            payloadbits[76] = 1;    // c
            payloadbits[84] = 1;    // d
            payloadbits[69] = 1;    // f
            payloadbits[72] = 1;    // g
            break;
            
        default:
            break;
        }
        break;
    case 1:
        if(dots[1])
            payloadbits[86] = 1;
        if(commas[1])
            payloadbits[89] = 1;
        switch (value)
        {
        case 0:
            payloadbits[60] = 1;    // a
            payloadbits[63] = 1;    // b
            payloadbits[75] = 1;    // c
            payloadbits[83] = 1;    // d
            payloadbits[80] = 1;    // e
            payloadbits[68] = 1;    // f
            break;
        case 1:
            payloadbits[63] = 1;    // b
            payloadbits[75] = 1;    // c
            break;
        case 2:
            payloadbits[60] = 1;    // a
            payloadbits[63] = 1;    // b
            payloadbits[83] = 1;    // d
            payloadbits[80] = 1;    // e
            payloadbits[71] = 1;    // g
            break;
        case 3:
            payloadbits[60] = 1;    // a
            payloadbits[63] = 1;    // b
            payloadbits[75] = 1;    // c
            payloadbits[83] = 1;    // d
            payloadbits[71] = 1;    // g
            break;
        case 4:
            payloadbits[63] = 1;    // b
            payloadbits[75] = 1;    // c
            payloadbits[68] = 1;    // f
            payloadbits[71] = 1;    // g
            break;
        case 5:
            payloadbits[60] = 1;    // a
            payloadbits[75] = 1;    // c
            payloadbits[83] = 1;    // d
            payloadbits[68] = 1;    // f
            payloadbits[71] = 1;    // g
            break;
        case 6:
            payloadbits[60] = 1;    // a
            payloadbits[75] = 1;    // c
            payloadbits[83] = 1;    // d
            payloadbits[80] = 1;    // e
            payloadbits[68] = 1;    // f
            payloadbits[71] = 1;    // g
            break;
        case 7:
            payloadbits[60] = 1;    // a
            payloadbits[63] = 1;    // b
            payloadbits[75] = 1;    // c
            break;
        case 8:
            payloadbits[60] = 1;    // a
            payloadbits[63] = 1;    // b
            payloadbits[75] = 1;    // c
            payloadbits[83] = 1;    // d
            payloadbits[80] = 1;    // e
            payloadbits[68] = 1;    // f
            payloadbits[71] = 1;    // g
            break;
        case 9:
            payloadbits[60] = 1;    // a
            payloadbits[63] = 1;    // b
            payloadbits[75] = 1;    // c
            payloadbits[83] = 1;    // d
            payloadbits[68] = 1;    // f
            payloadbits[71] = 1;    // g
            break;
        default:
            break;
        }
    case 2:
        if(dots[2])
            payloadbits[85] = 1;
        if(commas[2])
            payloadbits[88] = 1;

        switch (value)
        {
        case 0:
            payloadbits[59] = 1;    // a
            payloadbits[62] = 1;    // b
            payloadbits[74] = 1;    // c
            payloadbits[82] = 1;    // d
            payloadbits[79] = 1;    // e
            payloadbits[67] = 1;    // f
            break;
        case 1:
            payloadbits[62] = 1;    // b
            payloadbits[74] = 1;    // c
            break;
        case 2:
            payloadbits[59] = 1;    // a
            payloadbits[62] = 1;    // b
            payloadbits[82] = 1;    // d
            payloadbits[79] = 1;    // e
            payloadbits[70] = 1;    // g
            break;
        case 3:
            payloadbits[59] = 1;    // a
            payloadbits[62] = 1;    // b
            payloadbits[74] = 1;    // c
            payloadbits[82] = 1;    // d
            payloadbits[70] = 1;    // g
            break;
        case 4:
            payloadbits[62] = 1;    // b
            payloadbits[74] = 1;    // c
            payloadbits[67] = 1;    // f
            payloadbits[70] = 1;    // g
            break;
        case 5:
            payloadbits[59] = 1;    // a
            payloadbits[74] = 1;    // c
            payloadbits[82] = 1;    // d
            payloadbits[67] = 1;    // f
            payloadbits[70] = 1;    // g
            break;
        case 6:
            payloadbits[59] = 1;    // a
            payloadbits[74] = 1;    // c
            payloadbits[82] = 1;    // d
            payloadbits[79] = 1;    // e
            payloadbits[67] = 1;    // f
            payloadbits[70] = 1;    // g
            break;
        case 7:
            payloadbits[59] = 1;    // a
            payloadbits[62] = 1;    // b
            payloadbits[74] = 1;    // c
            break;
        case 8:
            payloadbits[59] = 1;    // a
            payloadbits[62] = 1;    // b
            payloadbits[74] = 1;    // c
            payloadbits[82] = 1;    // d
            payloadbits[79] = 1;    // e
            payloadbits[67] = 1;    // f
            payloadbits[70] = 1;    // g
            break;
        case 9:
            payloadbits[59] = 1;    // a
            payloadbits[62] = 1;    // b
            payloadbits[74] = 1;    // c
            payloadbits[82] = 1;    // d
            payloadbits[67] = 1;    // f
            payloadbits[70] = 1;    // g
            break;
        default:
            break;
        }
        break;
    case 3:
        if(dots[3])
            payloadbits[87] = 1;
        if(commas[3])
            payloadbits[90] = 1;

        if(colons[0][0])
            payloadbits[66] = 1;
        if(colons[1][0])
            payloadbits[78] = 1;

        switch (value)
        {
        case 0:
            payloadbits[61] = 1;    // a
            payloadbits[64] = 1;    // b
            payloadbits[76] = 1;    // c
            payloadbits[84] = 1;    // d
            payloadbits[81] = 1;    // e
            payloadbits[69] = 1;    // f
            break;
        case 1:
            payloadbits[64] = 1;    // b
            payloadbits[76] = 1;    // c
            break;
        case 2:
            payloadbits[61] = 1;    // a
            payloadbits[64] = 1;    // b
            payloadbits[84] = 1;    // d
            payloadbits[81] = 1;    // e
            payloadbits[72] = 1;    // g
            break;
        case 3:
            payloadbits[61] = 1;    // a
            payloadbits[64] = 1;    // b
            payloadbits[76] = 1;    // c
            payloadbits[84] = 1;    // d
            payloadbits[72] = 1;    // g
            break;
        case 4:
            payloadbits[64] = 1;    // b
            payloadbits[76] = 1;    // c
            payloadbits[69] = 1;    // f
            payloadbits[72] = 1;    // g
            break;
        case 5:
            payloadbits[61] = 1;    // a
            payloadbits[76] = 1;    // c
            payloadbits[84] = 1;    // d
            payloadbits[69] = 1;    // f
            payloadbits[72] = 1;    // g
            break;
        case 6:
            payloadbits[61] = 1;    // a
            payloadbits[76] = 1;    // c
            payloadbits[84] = 1;    // d
            payloadbits[81] = 1;    // e
            payloadbits[69] = 1;    // f
            payloadbits[72] = 1;    // g
            break;
        case 7:
            payloadbits[61] = 1;    // a
            payloadbits[64] = 1;    // b
            payloadbits[76] = 1;    // c
            break;
        case 8:
            payloadbits[61] = 1;    // a
            payloadbits[64] = 1;    // b
            payloadbits[76] = 1;    // c
            payloadbits[84] = 1;    // d
            payloadbits[81] = 1;    // e
            payloadbits[69] = 1;    // f
            payloadbits[72] = 1;    // g
            break;
        case 9:
            payloadbits[61] = 1;    // a
            payloadbits[64] = 1;    // b
            payloadbits[76] = 1;    // c
            payloadbits[84] = 1;    // d
            payloadbits[69] = 1;    // f
            payloadbits[72] = 1;    // g
            break;
            
        default:
            break;
        }
        break;
    case 4:
        if(dots[4])
            payloadbits[86] = 1;
        if(commas[4])
            payloadbits[89] = 1;
        switch (value)
        {
        case 0:
            payloadbits[60] = 1;    // a
            payloadbits[63] = 1;    // b
            payloadbits[75] = 1;    // c
            payloadbits[83] = 1;    // d
            payloadbits[80] = 1;    // e
            payloadbits[68] = 1;    // f
            break;
        case 1:
            payloadbits[63] = 1;    // b
            payloadbits[75] = 1;    // c
            break;
        case 2:
            payloadbits[60] = 1;    // a
            payloadbits[63] = 1;    // b
            payloadbits[83] = 1;    // d
            payloadbits[80] = 1;    // e
            payloadbits[71] = 1;    // g
            break;
        case 3:
            payloadbits[60] = 1;    // a
            payloadbits[63] = 1;    // b
            payloadbits[75] = 1;    // c
            payloadbits[83] = 1;    // d
            payloadbits[71] = 1;    // g
            break;
        case 4:
            payloadbits[63] = 1;    // b
            payloadbits[75] = 1;    // c
            payloadbits[68] = 1;    // f
            payloadbits[71] = 1;    // g
            break;
        case 5:
            payloadbits[60] = 1;    // a
            payloadbits[75] = 1;    // c
            payloadbits[83] = 1;    // d
            payloadbits[68] = 1;    // f
            payloadbits[71] = 1;    // g
            break;
        case 6:
            payloadbits[60] = 1;    // a
            payloadbits[75] = 1;    // c
            payloadbits[83] = 1;    // d
            payloadbits[80] = 1;    // e
            payloadbits[68] = 1;    // f
            payloadbits[71] = 1;    // g
            break;
        case 7:
            payloadbits[60] = 1;    // a
            payloadbits[63] = 1;    // b
            payloadbits[75] = 1;    // c
            break;
        case 8:
            payloadbits[60] = 1;    // a
            payloadbits[63] = 1;    // b
            payloadbits[75] = 1;    // c
            payloadbits[83] = 1;    // d
            payloadbits[80] = 1;    // e
            payloadbits[68] = 1;    // f
            payloadbits[71] = 1;    // g
            break;
        case 9:
            payloadbits[60] = 1;    // a
            payloadbits[63] = 1;    // b
            payloadbits[75] = 1;    // c
            payloadbits[83] = 1;    // d
            payloadbits[68] = 1;    // f
            payloadbits[71] = 1;    // g
            break;
        default:
            break;
        }
    case 5:
        if(dots[5])
            payloadbits[85] = 1;
        if(commas[5])
            payloadbits[88] = 1;
        switch (value)
        {
        case 0:
            payloadbits[59] = 1;    // a
            payloadbits[62] = 1;    // b
            payloadbits[74] = 1;    // c
            payloadbits[82] = 1;    // d
            payloadbits[79] = 1;    // e
            payloadbits[67] = 1;    // f
            break;
        case 1:
            payloadbits[62] = 1;    // b
            payloadbits[74] = 1;    // c
            break;
        case 2:
            payloadbits[59] = 1;    // a
            payloadbits[62] = 1;    // b
            payloadbits[82] = 1;    // d
            payloadbits[79] = 1;    // e
            payloadbits[70] = 1;    // g
            break;
        case 3:
            payloadbits[59] = 1;    // a
            payloadbits[62] = 1;    // b
            payloadbits[74] = 1;    // c
            payloadbits[82] = 1;    // d
            payloadbits[70] = 1;    // g
            break;
        case 4:
            payloadbits[62] = 1;    // b
            payloadbits[74] = 1;    // c
            payloadbits[67] = 1;    // f
            payloadbits[70] = 1;    // g
            break;
        case 5:
            payloadbits[59] = 1;    // a
            payloadbits[74] = 1;    // c
            payloadbits[82] = 1;    // d
            payloadbits[67] = 1;    // f
            payloadbits[70] = 1;    // g
            break;
        case 6:
            payloadbits[59] = 1;    // a
            payloadbits[74] = 1;    // c
            payloadbits[82] = 1;    // d
            payloadbits[79] = 1;    // e
            payloadbits[67] = 1;    // f
            payloadbits[70] = 1;    // g
            break;
        case 7:
            payloadbits[59] = 1;    // a
            payloadbits[62] = 1;    // b
            payloadbits[74] = 1;    // c
            break;
        case 8:
            payloadbits[59] = 1;    // a
            payloadbits[62] = 1;    // b
            payloadbits[74] = 1;    // c
            payloadbits[82] = 1;    // d
            payloadbits[79] = 1;    // e
            payloadbits[67] = 1;    // f
            payloadbits[70] = 1;    // g
            break;
        case 9:
            payloadbits[59] = 1;    // a
            payloadbits[62] = 1;    // b
            payloadbits[74] = 1;    // c
            payloadbits[82] = 1;    // d
            payloadbits[67] = 1;    // f
            payloadbits[70] = 1;    // g
            break;
        default:
            break;
        }
        break;    
    case 6:
        if(colons[0][1])
            payloadbits[66] = 1;
        if(colons[1][1])
            payloadbits[78] = 1;
        
        switch (value)
        {
        case 0:
            payloadbits[61] = 1;    // a
            payloadbits[64] = 1;    // b
            payloadbits[76] = 1;    // c
            payloadbits[84] = 1;    // d
            payloadbits[81] = 1;    // e
            payloadbits[69] = 1;    // f
            break;
        case 1:
            payloadbits[64] = 1;    // b
            payloadbits[76] = 1;    // c
            break;
        case 2:
            payloadbits[61] = 1;    // a
            payloadbits[64] = 1;    // b
            payloadbits[84] = 1;    // d
            payloadbits[81] = 1;    // e
            payloadbits[72] = 1;    // g
            break;
        case 3:
            payloadbits[61] = 1;    // a
            payloadbits[64] = 1;    // b
            payloadbits[76] = 1;    // c
            payloadbits[84] = 1;    // d
            payloadbits[72] = 1;    // g
            break;
        case 4:
            payloadbits[64] = 1;    // b
            payloadbits[76] = 1;    // c
            payloadbits[69] = 1;    // f
            payloadbits[72] = 1;    // g
            break;
        case 5:
            payloadbits[61] = 1;    // a
            payloadbits[76] = 1;    // c
            payloadbits[84] = 1;    // d
            payloadbits[69] = 1;    // f
            payloadbits[72] = 1;    // g
            break;
        case 6:
            payloadbits[61] = 1;    // a
            payloadbits[76] = 1;    // c
            payloadbits[84] = 1;    // d
            payloadbits[81] = 1;    // e
            payloadbits[69] = 1;    // f
            payloadbits[72] = 1;    // g
            break;
        case 7:
            payloadbits[61] = 1;    // a
            payloadbits[64] = 1;    // b
            payloadbits[76] = 1;    // c
            break;
        case 8:
            payloadbits[61] = 1;    // a
            payloadbits[64] = 1;    // b
            payloadbits[76] = 1;    // c
            payloadbits[84] = 1;    // d
            payloadbits[81] = 1;    // e
            payloadbits[69] = 1;    // f
            payloadbits[72] = 1;    // g
            break;
        case 9:
            payloadbits[61] = 1;    // a
            payloadbits[64] = 1;    // b
            payloadbits[76] = 1;    // c
            payloadbits[84] = 1;    // d
            payloadbits[69] = 1;    // f
            payloadbits[72] = 1;    // g
            break;
        default:
            break;
        }
    default:
        break;
    }

    for(int i = 56; i < 95; ++i)
        payload[(i / 8)-1] |= (payloadbits[i] << (7 - (i % 8)));
}