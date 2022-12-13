#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <gmp.h>
#include <gmpxx.h>

using namespace std;

void pi_gl() {
	mpf_t a, A, b, B, C, e, E, t, T, p, P, y;
	mpz_t i, j;
	int chars;
	
	// define precision
	double prec;
	prec = 1e10;
	
	mpf_t D;
	mpf_init(D);
	
	mpf_set_str(D, "1e-1000000000", 10);
	mpf_set_default_prec(prec);
	
	mpf_init(y);
	mpf_init(A);
	mpf_init(B);
	mpf_init(P);
	mpf_init(T);
	
	//set a = 1
	mpf_init_set_si(a, 1);
	//set b = 1/sqrt(2)
	mpf_init_set_str(b, "0.5", 10);
	mpf_sqrt(b, b);
	// set t = 0.25
	mpf_init_set_str(t, "0.25", 10);
	//set p = 1
	mpf_init_set_si(p, 1);
	//set e = 0
	mpf_init(e);
	//set E = 1
	mpf_init_set_si(E, 1);
	//set C = 1
	mpf_init_set_si(C, 1);
	
	//set i=0
	mpz_init(i);
	
	mpf_sub(y, E, e);
	// y is abs of difference between E and e
	mpf_abs(y, y);
	
	// now the loop
	while(mpf_cmp(y, D) >= 0){
		// e = E
		mpf_set(e, E);
		
		// A = (a+b)/2
		mpf_add(A, a, b);
		mpf_div_ui(A, A, 2);
		
		// B = sqrt(a*b)
		mpf_mul(B, a, b);
		mpf_sqrt(B, B);
		
		// T = t - p * (a - A)**2
		mpf_sub(T, a, A);
		mpf_pow_ui(T, T, 2);
		mpf_mul(T, p, T);
		mpf_sub(T, t, T);
		
		// P = 2 * p
		mpf_mul_ui(P, p, 2);
		
		// calculate estimate E = (A + B)**2 / (4*T) 
		mpf_add(E, A, B);
		mpf_pow_ui(E, E, 2);
		mpf_div(E, E, T);
		mpf_div_ui(E, E, 4);

		mpf_set(a, A);
		mpf_set(b, B);
		mpf_set(t, T);
		mpf_set(p, P);
		
		mpz_set(j, i);
		mpz_add_ui(i, j, 1);
		
		// calculate difference again
		mpf_sub(y, E, e);
		mpf_abs(y, y);

	}
	
	
	//mpf_out_str(stdout, 10, 1e6, E);
	
	
	chars = gmp_printf("%.*Ff", 1000000000, E);	
}


int main(void) {
	pi_gl();
	return 0;
}
