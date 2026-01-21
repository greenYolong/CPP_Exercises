cmake_minimum_required(VERSION 3.16)
project(modules)
#       ^^^^^^^^^^ nom du projet (ne pas mettre d'espace)

#              vvvvvvvvvvvvv Nom de l'executable
add_executable(my_executable  
    main.cpp  # \
    Rectangle.cpp  #  |
    # ...            |- Sources et headers
    Rectangle.hpp  # /
)

target_compile_features(my_executable PRIVATE cxx_std_17)
    # Pour compiler avec le standard C++17   ^^^^^^^^^^

target_compile_options(my_executable PRIVATE  # <- Ajoute des flags à la compilation
    -Wall  # Ajoute des warnings
    -Wextra  # Ajoute plus de warnings
    -Werror  # Transforme les warnings en erreurs
)