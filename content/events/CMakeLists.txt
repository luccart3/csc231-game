add_library(events
  updatefov.cpp
        hit.cpp
        die.cpp
        thrust.cpp
        swing.h
        swing.cpp
        animation.cpp
        sound.cpp
        recover.h
        recover.cpp
        drink.h
        drink.cpp
        raise.h
        raise.cpp
        remove_item.h
        remove_item.cpp
)

target_include_directories(events PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(events PUBLIC engine)
