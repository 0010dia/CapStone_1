/*
 * Copyright 1992 by Jutta Degener and Carsten Bormann, Technische
 * Universitaet Berlin.  See the accompanying file "COPYRIGHT" for
 * details.  THERE IS ABSOLUTELY NO WARRANTY FOR THIS SOFTWARE.
 */


#ifndef	GSM_H
#define	GSM_H

#ifdef __cplusplus
extern "C" {
#endif

#define GSM_SAMPLES_PER_FRAME       160
#define GSM_ENCODED_FRAME_SIZE      33

#undef USE_FLOAT_MUL


/* The GSM_OPT_LTP_CUT option speeds up encoding by using an alternate */
/* faster algorithm to calculate the long term predictor */
#define	GSM_OPT_LTP_CUT		3

struct gsm_state *  gsm_create(void);
void gsm_destroy(struct gsm_state * st);

int  gsm_option(struct gsm_state * st, int, int *);

int  gsm_encode(struct gsm_state * st, short *in, unsigned char  *out);
int  gsm_decode(struct gsm_state * st, unsigned char *in, short *out);

#ifdef __cplusplus
}  /* extern "C" */
#endif

#endif	/* GSM_H */
