
// This file is part of the MDCII Game Engine.
// Copyright (C) 2015  Benedikt Freisen
// 
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

#include <stdlib.h>
#include <inttypes.h>
#include <SDL/SDL.h>

#include "palette.hpp"
#include "kamera.hpp"

Uint32 timer_callback(Uint32 interval, void *param)
{
  SDL_Event event;
  SDL_UserEvent userevent;

  // push an SDL_USEREVENT event into the queue

  userevent.type = SDL_USEREVENT;
  userevent.code = 0;
  userevent.data1 = NULL;
  userevent.data2 = NULL;

  event.type = SDL_USEREVENT;
  event.user = userevent;

  SDL_PushEvent(&event);
  return(interval);
}

int main(int argc, char **argv)
{
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
  {
    exit(EXIT_FAILURE);
  }
  atexit(SDL_Quit);
  
  int screen_width = 800;
  int screen_height = 600;
  
  SDL_Surface *screen;
  screen = SDL_SetVideoMode(screen_width, screen_height, 8, SDL_SWSURFACE);
  
  SDL_Color colors[256];
  int i, j;
  for (i = 0, j = 0; i < 256; i++)
  {
    colors[i].r = palette[j++];
    colors[i].g = palette[j++];
    colors[i].b = palette[j++];
  }
  SDL_SetPalette(screen, SDL_LOGPAL|SDL_PHYSPAL, colors, 0, 256);
  
  
  
  
  std::ifstream f;
  f.open("game00.gam");
  
  Welt welt = Welt(f);
  
  f.close();
  
  Bildspeicher bs(screen_width, screen_height, 1, 0, (uint8_t *)screen->pixels);
  
  Kamera kamera;
  kamera.zeichne_bild(bs, welt);
  
  SDL_UpdateRect(screen, 0, 0, screen_width, screen_height);
  
  
  
  
  SDL_TimerID timer_id = SDL_AddTimer(100, timer_callback, NULL);
  Uint8 *keystate = SDL_GetKeyState(NULL);
  
  SDL_Event e;
  while(1)
  {
    SDL_WaitEvent(&e);
    switch (e.type)
    {
      case SDL_QUIT:
	exit(EXIT_SUCCESS);
	break;
      case SDL_USEREVENT:
	if (keystate[SDLK_LEFT])
	{
	  kamera.nach_links();
	}
	if (keystate[SDLK_RIGHT])
	{
	  kamera.nach_rechts();
	}
	if (keystate[SDLK_UP])
	{
	  kamera.nach_oben();
	}
	if (keystate[SDLK_DOWN])
	{
	  kamera.nach_unten();
	}
	
	welt.simulationsschritt();
	kamera.zeichne_bild(bs, welt);
	SDL_UpdateRect(screen, 0, 0, screen_width, screen_height);
	break;
      case SDL_KEYDOWN:
	if (e.key.keysym.sym == SDLK_F2)
	{
	  kamera.setze_vergroesserung(0);
	}
	if (e.key.keysym.sym == SDLK_F3)
	{
	  kamera.setze_vergroesserung(1);
	}
	if (e.key.keysym.sym == SDLK_F4)
	{
	  kamera.setze_vergroesserung(2);
	}
	if (e.key.keysym.sym == SDLK_x)
	{
	  kamera.rechts_drehen();
	}
	if (e.key.keysym.sym == SDLK_y)
	{
	  kamera.links_drehen();
	}
	break;
    }
  }
}
