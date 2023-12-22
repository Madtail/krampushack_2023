
#include "main.h"

int SCREEN_W{ 800 };
int SCREEN_H{ 600 };
int PLAYER_WIDTH{ 32 };
int PLAYER_HEIGHT{ 32 };
int BACKGROUND_WIDTH{ 3840 };
int BACKGROUND_HEIGHT{ 2160 };

int main(int argc, char const** argv)
{
	startSystems();

	al_start_timer(timer);

	double fps = 0;
	int frames_done = 0;
	double old_time = al_get_time();

	int frames_skipped{ 0 };

	int playerKeyUp = 0;

	Scene director(SCENE_TYPE::GAME);

	bool running{ true };
	bool draw{ false };
	while (running) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(queue, &ev);

		switch (ev.type) {
		case ALLEGRO_EVENT_KEY_DOWN:
			if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				// Note: IN THE FUTURE THIS WILL BE HANDLED by the Scene class {director}.
				running = false;
			}

			director.input.setKey(ev.keyboard.keycode);

			break;
		case ALLEGRO_EVENT_KEY_UP:
			director.input.unsetKey(ev.keyboard.keycode);
				playerKeyUp = ev.keyboard.keycode;
			break;
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			running = false;
			break;
		case ALLEGRO_EVENT_TIMER:
			running = director.Update(ev, playerKeyUp);
			playerKeyUp = 0;
			draw = true;
			break;
		}

		if (draw && al_is_event_queue_empty(queue)) {

			double game_time = al_get_time();
			if ((game_time - old_time) >= 1.0) {
				fps = frames_done / (game_time - old_time);
				frames_done = 0;
				old_time = game_time;
			}
			frames_done++;
	
			ALLEGRO_COLOR color = al_map_rgb_f(0.0f, 0.0f, 0.0f);
			al_clear_to_color(color);

			std::string fps_text = "FPS: " + std::to_string(fps);

			// Main draw
			director.Draw();

			// draw fps
			al_draw_text(font, al_map_rgb(255, 255, 255), 0, 0, 0, fps_text.c_str());

			al_flip_display();

			draw = false;
		}
	}
	
	al_destroy_font(font);
	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_event_queue(queue);
	return 0;
}

inline void must_init(bool subsystem, const char* message)
{
	if (!subsystem) {
		std::cerr << message << "\n";
		exit(EXIT_FAILURE);
	}
}

inline void* must_exist(void* val, const char* message)
{
	if (!val) {
		std::cerr << message << "\n";
		exit(EXIT_FAILURE);
	}

	return val;
}

void startSystems()
{
	must_init(al_init(), "ALLEGRO 5 FAILED TO INITIALIZE!");

#ifdef WIN32
	al_set_new_display_flags(ALLEGRO_OPENGL_3_0);
#endif // WIN32

	//al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
	al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
	al_set_new_display_option(ALLEGRO_SAMPLES, 4, ALLEGRO_SUGGEST);

	display = (ALLEGRO_DISPLAY*)must_exist(al_create_display(SCREEN_W, SCREEN_H), "FATAL ERROR: display ");
	queue = (ALLEGRO_EVENT_QUEUE*)must_exist(al_create_event_queue(), "FATAL ERROR: queue ");
	timer = (ALLEGRO_TIMER*)must_exist(al_create_timer(1.0 / FPS), "FATAL ERROR: timer ");
	font = (ALLEGRO_FONT*)must_exist(al_create_builtin_font(), "FATAL ERROR: font");

	must_init(al_install_keyboard(), "KEYBOARD DRIVER ERROR!");
	must_init(al_init_image_addon(), "IMAGE ADD-ON ERROR!");
	must_init(al_init_primitives_addon(), "PRIMITIVES ADD-ON ERROR!");
	must_init(al_init_font_addon(), "FONT ADD-ON ERROR!");
	must_init(al_init_ttf_addon(), "TTF FONT ADD-ON ERROR!");

	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_timer_event_source(timer));

	SCREEN_W = al_get_display_width(display);
	SCREEN_H = al_get_display_height(display);
}

bool collide(Rect a, Rect b)
{
	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	//Calculate the sides of rect B
	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;

	//If any of the sides from A are outside of B
	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

	//If none of the sides from A are outside B
	return true;
}