add_library(actions
  rest.cpp
        move.cpp
        opendoor.cpp
        closedoor.cpp
        wander.cpp
        attack.cpp
        use_item.h
        use_item.cpp
        interact.h
        interact.cpp
)

target_include_directories(actions PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(actions PUBLIC engine events)
