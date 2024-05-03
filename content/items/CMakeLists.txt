add_library(items
  bite.cpp
        spiked_club.cpp
        spear.h
        spear.cpp
        sword_rusty.h
        sword_rusty.cpp
        healing_potion.h
        healing_potion.cpp
        lightning_staff.cpp
        ladder.h
        ladder.cpp
)

target_include_directories(items PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(items PUBLIC engine events)
