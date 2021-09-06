/* Float arithmetic
 *
 * (c) Copyright 1999, Artran, Inc.
 * Written by Greg Garner (gmg@artran.com)
 * Modified in March 2001 to include user defined
 * operators for the floating point functions.
 *
 * This file is provided as is (no warranties).
 */
#pragma library Float

/**************************************************/
/* Convert an integer into a floating point value */
native Float:float(value) = -1000;

/**************************************************/
/* Multiple two floats together */
native Float:fmulf(Float:oper1, Float:oper2) = -1002;

/**************************************************/
/* Divide the dividend float by the divisor float */
native Float:fdivf(Float:dividend, Float:divisor) = -1003;

/**************************************************/
/* Add two floats together */
native Float:faddf(Float:oper1, Float:oper2) = -1004;

/**************************************************/
/* Subtract oper2 float from oper1 float */
native Float:fsubf(Float:oper1, Float:oper2) = -1005;

/**************************************************/
/* Return the fractional part of a float */
native Float:floatfract(Float:value) = -1006;

/**************************************************/
/* Round a float into a integer value */
native       roundf(Float:value) = -1007;

/**************************************************/
/* Compare two integers. If the two elements are equal, return 0.
   If the first argument is greater than the second argument, return 1,
   If the first argument is less than the second argument, return -1. */
native       floatcmp(Float:oper1, Float:oper2) = -1008;

/**************************************************/
/* Return the sine, cosine or tangent. The input angle may be in radian,
   degrees or grades. */
native Float:sinf(Float:value) = -1012;
native Float:cosf(Float:value) = -1013;
stock Float:tanf(Float:value) {
    return sinf(value) / cosf(value);
}

/**************************************************/
/* Return the absolute value */
native Float:fabsf(Float:value) = -1015;


/**************************************************/
#pragma rational Float

/* user defined operators */
native Float:operator*(Float:oper1, Float:oper2) = -1002; // Same as fmulf
native Float:operator/(Float:oper1, Float:oper2) = -1003; // Same as fdivf
native Float:operator+(Float:oper1, Float:oper2) = -1004; // Same as faddf
native Float:operator-(Float:oper1, Float:oper2) = -1005; // Same as fsubf
native Float:operator=(oper) = -1000; // Same as Float:float(value)

stock Float:operator++(Float:oper)
    return oper+1.0;

stock Float:operator--(Float:oper)
    return oper-1.0;

stock Float:operator-(Float:oper)
    return oper^Float:cellmin;                  /* IEEE values are sign/magnitude */

stock Float:operator*(Float:oper1, oper2)
    return fmulf(oper1, float(oper2));       /* "*" is commutative */

stock Float:operator/(Float:oper1, oper2)
    return fdivf(oper1, float(oper2));

stock Float:operator/(oper1, Float:oper2)
    return fdivf(float(oper1), oper2);

stock Float:operator+(Float:oper1, oper2)
    return faddf(oper1, float(oper2));       /* "+" is commutative */

stock Float:operator-(Float:oper1, oper2)
    return fsubf(oper1, float(oper2));

stock Float:operator-(oper1, Float:oper2)
    return fsubf(float(oper1), oper2);

stock bool:operator==(Float:oper1, Float:oper2)
    return floatcmp(oper1, oper2) == 0;

stock bool:operator==(Float:oper1, oper2)
    return floatcmp(oper1, float(oper2)) == 0;  /* "==" is commutative */

stock bool:operator!=(Float:oper1, Float:oper2)
    return floatcmp(oper1, oper2) != 0;

stock bool:operator!=(Float:oper1, oper2)
    return floatcmp(oper1, float(oper2)) != 0;  /* "!=" is commutative */

stock bool:operator>(Float:oper1, Float:oper2)
    return floatcmp(oper1, oper2) > 0;

stock bool:operator>(Float:oper1, oper2)
    return floatcmp(oper1, float(oper2)) > 0;

stock bool:operator>(oper1, Float:oper2)
    return floatcmp(float(oper1), oper2) > 0;

stock bool:operator>=(Float:oper1, Float:oper2)
    return floatcmp(oper1, oper2) >= 0;

stock bool:operator>=(Float:oper1, oper2)
    return floatcmp(oper1, float(oper2)) >= 0;

stock bool:operator>=(oper1, Float:oper2)
    return floatcmp(float(oper1), oper2) >= 0;

stock bool:operator<(Float:oper1, Float:oper2)
    return floatcmp(oper1, oper2) < 0;

stock bool:operator<(Float:oper1, oper2)
    return floatcmp(oper1, float(oper2)) < 0;

stock bool:operator<(oper1, Float:oper2)
    return floatcmp(float(oper1), oper2) < 0;

stock bool:operator<=(Float:oper1, Float:oper2)
    return floatcmp(oper1, oper2) <= 0;

stock bool:operator<=(Float:oper1, oper2)
    return floatcmp(oper1, float(oper2)) <= 0;

stock bool:operator<=(oper1, Float:oper2)
    return floatcmp(float(oper1), oper2) <= 0;

stock bool:operator!(Float:oper)
    return (_:oper & cellmax) == 0;

/* forbidden operations */
forward operator%(Float:oper1, Float:oper2);
forward operator%(Float:oper1, oper2);
forward operator%(oper1, Float:oper2);

