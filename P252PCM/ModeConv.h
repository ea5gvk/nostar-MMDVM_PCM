/*
 *   Copyright (C) 2010,2014,2016 by Jonathan Naylor G4KLX
 *   Copyright (C) 2018 by Andy Uribe CA6JAU
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include "RingBuffer.h"
#include "imbe_vocoder_api.h"

const unsigned char TAG_HEADER = 0x00U;
const unsigned char TAG_DATA   = 0x01U;
const unsigned char TAG_LOST   = 0x02U;
const unsigned char TAG_EOT    = 0x03U;
const unsigned char TAG_NODATA = 0x04U;

#if !defined(MODECONV_H)
#define MODECONV_H

class CModeConv {
public:
	CModeConv();
	~CModeConv();

	void putP25(unsigned char* bytes);
	unsigned int getP25(unsigned char* bytes);
	
	void putPCMHeader(int16_t *pcm);
	void putPCM(int16_t* pcm);
	void putPCMEOT(int16_t *pcm);
	bool getPCM(int16_t* pcm);

private:
	void decode_4400(int16_t *, uint8_t *);
	void encode_4400(int16_t *, uint8_t *);
	unsigned int m_p25N;
	unsigned int m_pcmN;
	CRingBuffer<unsigned char> m_P25;
	CRingBuffer<int16_t> m_PCM;
	imbe_vocoder vocoder;
};

#endif
