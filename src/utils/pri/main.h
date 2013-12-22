/*****************************************************************************
 * pce                                                                       *
 *****************************************************************************/

/*****************************************************************************
 * File name:   src/utils/pri/main.h                                         *
 * Created:     2012-01-31 by Hampa Hug <hampa@hampa.ch>                     *
 * Copyright:   (C) 2012-2013 Hampa Hug <hampa@hampa.ch>                     *
 *****************************************************************************/

/*****************************************************************************
 * This program is free software. You can redistribute it and / or modify it *
 * under the terms of the GNU General Public License version 2 as  published *
 * by the Free Software Foundation.                                          *
 *                                                                           *
 * This program is distributed in the hope  that  it  will  be  useful,  but *
 * WITHOUT  ANY   WARRANTY,   without   even   the   implied   warranty   of *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU  General *
 * Public License for more details.                                          *
 *****************************************************************************/


#ifndef PRI_MAIN_H
#define PRI_MAIN_H 1


#include <config.h>

#include <drivers/pri/pri.h>
#include <drivers/psi/psi.h>


extern const char    *arg0;

extern int           par_verbose;

extern int           par_list;
extern int           par_print_info;

extern int           par_cyl_all;
extern unsigned long par_cyl[2];

extern int           par_trk_all;
extern unsigned long par_trk[2];

extern unsigned long par_data_rate;


typedef int (*pri_trk_cb) (pri_img_t *img, pri_trk_t *trk,
	unsigned long c, unsigned long h, void *opaque
);


int pri_for_all_tracks (pri_img_t *img, pri_trk_cb fct, void *opaque);

int pri_comment_add (pri_img_t *img, const char *str);
int pri_comment_load (pri_img_t *img, const char *fname);
int pri_comment_save (pri_img_t *img, const char *fname);
int pri_comment_set (pri_img_t *img, const char *str);
int pri_comment_show (pri_img_t *img);

int pri_decode_raw (pri_img_t *img, const char *fname);
int pri_decode (pri_img_t *img, const char *type, const char *fname);

int pri_delete_tracks (pri_img_t *img);
int pri_double_step (pri_img_t *img, int even);

int pri_edit_tracks (pri_img_t *img, const char *what, const char *val);

int pri_encode (pri_img_t **img, const char *type, const char *fname);

int pri_print_info (pri_img_t *img);

int pri_list_tracks (pri_img_t *img);

int pri_decode_mfm_text (pri_img_t *img, const char *fname);
int pri_encode_mfm_text (pri_img_t *img, const char *fname);

int pri_new (pri_img_t *img);

int pri_align_gcr_tracks (pri_img_t *img);
int pri_rotate_tracks (pri_img_t *img, unsigned long idx);


#endif
