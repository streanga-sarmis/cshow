//	cshow a simple slide show program.
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


#include <vector>

#include "slide.h"

namespace cshow {

	class slidemanager {

		private:
			static std::vector<slide>	slideVector;
			static uint32_t				index;
			
		public:
			slidemanager();

			static slide getCurrentSlide();
			static void pushSlideToQueue(const slide& slide);
			static void nextSlide();
			static void previousSlide();
			static void clearSlides();
	};

}