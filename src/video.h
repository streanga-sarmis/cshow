//  cshow a simple slide show program.
//
//	Copyright (C) 2017 Stephancode(Streanga Sarmis-Stefan).
//
//	This program is free software : you can redistribute it and / or modify
//	it under the terms of the GNU General Public License as published by
//	the Free Software Foundation, either version 3 of the License, or
//	(at your option) any later version.
//
//	This program is distributed in the hope that it will be useful,
//	but WITHOUT ANY WARRANTY; without even the implied warranty of
//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
//	GNU General Public License for more details.
//
//	You should have received a copy of the GNU General Public License
//	along with this program, if not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <SDL.h>

#include "vec2.h"
#include "fadecomponent.h"

extern "C" { 
	#include <libavcodec/avcodec.h>
	#include <libavformat/avformat.h>
	#include <libswscale/swscale.h>
}
namespace cshow {
	// @TODO  : public slidecomponent
	class video : public fadecomponent {

		private:
			bool				interrupt;
			vec2				size;
			vec2				position;
			SDL_Texture*		texture;
			SDL_Renderer*		renderer;
			SDL_Rect			rect;
			AVFormatContext*	pFormatCtx = NULL;
			AVCodecContext*		pCodecCtxOrig = NULL;
			AVCodecContext*		pCodecCtx = NULL;
			AVCodec*			pCodec = NULL;
			AVFrame*			pFrame = NULL;
			AVPacket			packet;
			Uint8*				yPlane;
			Uint8*				uPlane; 
			Uint8*				vPlane;
			Uint32				yPlaneSz, uvPlaneSz;
			struct SwsContext*	sws_ctx;
			int					uvPitch;
 			int					videoStream;
			int					frameFinished;

		public:
			video() = default;
			video(SDL_Renderer* renderer, const std::string& path, const vec2& position, const vec2& size);

			void clear();
			void render();
	};

}