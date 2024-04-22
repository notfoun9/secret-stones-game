file(REMOVE_RECURSE
  "libSDL2.a"
  "libSDL2.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/SDL2.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
