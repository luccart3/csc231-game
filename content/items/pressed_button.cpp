#include "pressed_button.h"
#include "engine.h"
#include "sound.h"

PressedButton::PressedButton()
    :Item{"pressed_button"} {}

void PressedButton::interact(Engine& engine, Entity&) {
    engine.events.create_event<Sound>("button-press");
}