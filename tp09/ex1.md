# Exercice 1 - Documentation (20 min)

1. Consulter la documentation des conteneurs spécifiés afin de renseigner les complexités en temps de chacune des opérations :

| Conteneur     | Insertion (en tête / en fin) | Suppression (en tête / en fin) |     Accès    |
|---------------|----------------------------- |--------------------------------|--------------|
| array         |     N/A                      |     N/A                        |     O(1)     |
| deque         |     O(1)                     |     O(1)                       |     O(1)     |
| forward_list  |     O(1)                     |     O(1)                       |     O(n)     |
| set           |     O(log(n))                |     O(log(n))                  |   O(log(n))  |
| unordered_map |     ~O(1)                    |     ~O(1)                      |     ~O(1)    |

2. Supposons que vous ayez récupéré un itérateur sur un élément d'un conteneur avec : `auto it = std::find(ctn.begin(), ctn.end(), element_to_find)`.  
En fonction du type de conteneur, quelles sont les opérations susceptibles d'invalider cet itérateur ?  
Exemple : Si `ctn` est un `std::vector`, alors `it` peut être invalidé en cas de suppression d'un élément précédent `it` dans le conteneur.
Répondre pour les conteneurs array, forward_list et unordered_map.

- pour array : `As a rule, iterators to an array are never invalidated throughout the lifetime of the array. One should take note, however, that during swap, the iterator will continue to point to the same array element, and will thus change its value.`
- pour deque : `shrink_to_fit, clear, insert, emplace, push_front, push_back, emplace_front, emplace_back` invalide it. `erase resize swap pop_front et pop_back` peuvent invalider it selon certaines conditions données [ici](https://en.cppreference.com/w/cpp/container/deque.html)
- pour forward_list :  `iterator or reference referring to an element is invalidated when the corresponding element is removed (via erase_after) from the list.`
- pour set : `the erase members shall invalidate only iterators and references to the erased elements.`
- pour unordered_map : `clear, rehash, reserve, operator=` invalide toujours, `insert, emplace, emplace_hint, operator[]` si ces opérations provoquent un rehash et `erase` invalide l'élément concerné.