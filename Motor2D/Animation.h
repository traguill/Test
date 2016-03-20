#ifndef __ANIMATION_H__
#define __ANIMATION_H__
 
#include "SDL\include\SDL.h"

using namespace std;
#include <vector>

class Animation
{
private:

	int loops;

public:

	float current_frame;
	bool loop;
	float speed;
	vector<SDL_Rect> frames;

	Animation() : frames(5), speed(1.0f), current_frame(0), loop(true), loops(0)
	{ }

	Animation(const Animation& a) : frames(a.frames), speed(a.speed), current_frame(0), loop(a.loop), loops(0)
	{ }

	SDL_Rect& getCurrentFrame()
	{
		current_frame += speed;
		if (current_frame >= frames.size())
		{
			current_frame = (loop) ? 0.0f : frames.size() - 1;
			loops++;
		}
		return frames[(int)current_frame];
	}

	const SDL_Rect &peekCurrentFrame() const
	{
		return frames[(int)current_frame];
	}

	bool finished()
	{
		return loops > 0;
	}

	void reset()
	{
		loops = 0;
		current_frame = 0;
	}

};


#endif // !__ANIMATION_H__