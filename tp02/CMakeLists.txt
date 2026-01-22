cmake_minimum_required(VERSION 3.16)
project(bataille)
#       ^^^^^^^^^^ nom du projet (ne pas mettre d'espace)

#              vvvvvvvvvvvvv Nom de l'executable
add_executable(bataille  
    main.cpp  # \
    Card.cpp  
    Player.cpp
    Color.cpp
    Value.cpp

    Card.hpp  
    Player.hpp
    Color.hpp
    Value.hpp
)

target_compile_features(bataille PRIVATE cxx_std_17)
    # Pour compiler avec le standard C++17   ^^^^^^^^^^

target_compile_options(bataille PRIVATE  # <- Ajoute des flags à la compilation
    -Wall  # Ajoute des warnings
    -Wextra  # Ajoute plus de warnings
    -Werror  # Transforme les warnings en erreurs
)