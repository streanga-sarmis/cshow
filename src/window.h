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
#include <SDL_ttf.h>
#include <SDL_Image.h>

#include "slidemanager.h"
#include "slidefilereader.h"
#include "vec3.h"

namespace cshow {


	class window {

		private:
			bool			running;
			SDL_Window*		sdlWindow;
			Uint32			width;
			Uint32			height;


		public:
			window();
			window(const vec3& properties);
			window(Uint32 width, Uint32 height, const char* title);
			~window();

			void run(SDL_Renderer* renderer, void(*renderCallback)(void), const slidefilereader& reader);

			SDL_Window* getWindow() const;
	};

}