# Warning: GLOB_RECURSE is strongly recommended _against_ as cmake is commonly
#          used by other build toolchains to auto detect differences in files.
#          As such, prefer listing out files manually.
# file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS *.cpp)
# file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS *.hpp)

# add_library creates a new library target
# STATIC     .a   Linux/Unix or .lib   Windows   and is bundled up as part of the final executable binary
# SHARED     .so  Linux/Unix or .dll   Windows   and is intended to be distributed separate from the final binary
# OBJECT     .o   just an object file
# INTERFACE  header only library, no compiled code

# but since this little project for raylib and games isn't intended to make a library
# to be linked in elsewhere, we're not going to do it.
# presume we had a main.cpp with an entry point only that imported game logic
# defined elsewhere, we'd create a library of our own game logic then
# link our final executable against it, e.g.:
#    add_library(GameLib STATIC)
#    target_sources(GameLib PRIVATE
#        game/game_loop.cpp
#        game/renderer.cpp
#        game/physics.cpp
#    )
#
#    target_sources(${PROJECT_NAME} PRIVATE
#        main.cpp
#    )
#    target_link_libraries(${PROJECT_NAME} PRIVATE GameLib)
#
# If unsure of whether or not you need libraries, skip them.
# Just add your files one by one under target_sources() down below
# Then, when it becomes apparent that there's a group of source files
# and headers that all do one particular thing that's helpful to
# but not strictly speaking a part of the exact game you're making
# (like players and enemies) and you've got a good sense of the
# abstraction between your game and the behaviors of those source files
# and headers, THEN create a library because you could then re-use
# that library elsewhere in another game or in another part of your game
# if it got super complicated.

# target_sources specifies visibility (unsure how that's enforced, but let's just take cmake at its word)
# PRIVATE   only this target and these sources
# PUBLIC    this target uses them and anyone linking to this library
# INTERFACE this target doesn't use them, but anyone linking to this library gets them
target_sources(${PROJECT_NAME} PRIVATE
    main.cpp
    # add other files as necessary but list them out
    # helpers/foo.cpp
    # npcs/boss.cpp
)
