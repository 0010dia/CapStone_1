#ifndef __SGL_MD5_H
#define __SGL_MD5_H

#pragma once

#define MD5_MASTERKEY "DCB0E9A5354748C9A8F6176CB72F5CD4"

/*
* End of T computation program.
*/
#define MT1 0xd76aa478
#define MT2 0xe8c7b756
#define MT3 0x242070db
#define MT4 0xc1bdceee
#define MT5 0xf57c0faf
#define MT6 0x4787c62a
#define MT7 0xa8304613
#define MT8 0xfd469501
#define MT9 0x698098d8
#define MT10 0x8b44f7af
#define MT11 0xffff5bb1
#define MT12 0x895cd7be
#define MT13 0x6b901122
#define MT14 0xfd987193
#define MT15 0xa679438e
#define MT16 0x49b40821
#define MT17 0xf61e2562
#define MT18 0xc040b340
#define MT19 0x265e5a51
#define MT20 0xe9b6c7aa
#define MT21 0xd62f105d
#define MT22 0x02441453
#define MT23 0xd8a1e681
#define MT24 0xe7d3fbc8
#define MT25 0x21e1cde6
#define MT26 0xc33707d6
#define MT27 0xf4d50d87
#define MT28 0x455a14ed
#define MT29 0xa9e3e905
#define MT30 0xfcefa3f8
#define MT31 0x676f02d9
#define MT32 0x8d2a4c8a
#define MT33 0xfffa3942
#define MT34 0x8771f681
#define MT35 0x6d9d6122
#define MT36 0xfde5380c
#define MT37 0xa4beea44
#define MT38 0x4bdecfa9
#define MT39 0xf6bb4b60
#define MT40 0xbebfbc70
#define MT41 0x289b7ec6
#define MT42 0xeaa127fa
#define MT43 0xd4ef3085
#define MT44 0x04881d05
#define MT45 0xd9d4d039
#define MT46 0xe6db99e5
#define MT47 0x1fa27cf8
#define MT48 0xc4ac5665
#define MT49 0xf4292244
#define MT50 0x432aff97
#define MT51 0xab9423a7
#define MT52 0xfc93a039
#define MT53 0x655b59c3
#define MT54 0x8f0ccc92
#define MT55 0xffeff47d
#define MT56 0x85845dd1
#define MT57 0x6fa87e4f
#define MT58 0xfe2ce6e0
#define MT59 0xa3014314
#define MT60 0x4e0811a1
#define MT61 0xf7537e82
#define MT62 0xbd3af235
#define MT63 0x2ad7d2bb
#define MT64 0xeb86d391


/*
* This code has some adaptations for the Ghostscript environment, but it
* will compile and run correctly in any environment with 8-bit chars and
* 32-bit ints.  Specifically, it assumes that if the following are
* defined, they have the same meaning as in Ghostscript: P1, P2, P3,
* ARCH_IS_BIG_ENDIAN.
*/

typedef unsigned char md5_byte_t; /* 8-bit byte */
typedef unsigned int md5_word_t; /* 32-bit word */

/* Define the state of the MD5 Algorithm. */
typedef struct md5_state_s {
	md5_word_t count[2];	/* message length in bits, lsw first */
	md5_word_t abcd[4];		/* digest buffer */
	md5_byte_t buf[64];		/* accumulate block */
} md5_state_t;


class CSglMD5
{
public:
	CSglMD5(void);
public:
	~CSglMD5(void);

public:
	static void md5_init(md5_state_t* pms);
	static void md5_append(md5_state_t* pms, const md5_byte_t* data, int nbytes);
	static void md5_finish(md5_state_t* pms, md5_byte_t digest[16]);

protected:
	static void md5_process(md5_state_t* pms, const md5_byte_t* data);

};

#endif
