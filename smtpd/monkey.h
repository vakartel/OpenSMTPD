/*	$OpenBSD$	*/

/*
 * Copyright (c) 2012 Gilles Chehade <gilles@poolp.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef	_MONKEY_H_
#define	_MONKEY_H_

#if ! defined(USE_MONKEY)
#define MONKEY_RETURN(x)
#define MONKEY_PAUSE(x)
#define MONKEY_SET(x, y)

#else
#if ! defined(MONKEY_RATE)
#define	MONKEY_RATE		8
#endif
#define	MONKEY_RETURN(x)	do { if (!(arc4random() % MONKEY_RATE)) return (x); } while (0)
#define	MONKEY_PAUSE(x)		do { if (!(arc4random() % MONKEY_RATE)) sleep (x); } while (0)
#define	MONKEY_SET(x, y)       	do { if (!(arc4random() % MONKEY_RATE)) (x) = (y); } while (0)

#endif


#endif
