"Mille Petits Gestes" est une installation artistique conçu par MP0804h (Igor Deschamps) et réalisée en collaboration avec Derrick Giscloux.
Présentée au Musée de la Mine de Saint Etienne dans le cadre de la Fête de la Science 2018.

Techniques et Concepts utilisés:

Les artistes ont le bon goût d'avoir des exigences concernant la mise en scene qui impliquent un certain nombre de contraintes et de défi techniques.

Premier défi : Tirer une LED au hasard parmis N, sans jamais tirer deux fois la même, jusqu'à ce qu'elle ai toutes été tirées.

C'est le principe du jeux de carte qu'on mélange avant d'en distribuer les cartes une à une.
Problème connu, la fonction "Random", présente dans de nombreux language de programmation permet de tirer un nombre au hasard, mais il est tout à fait possible d'obtenir une longue série de nombres identiques (rare, peu probable, mais pas impossible!).

Afin de pallier à ce problème j'ai modélisé le comportement d'un jeux de cartes qu'on mélangerais, la fonction Random ne servant alors qu'au mélange d'un tableau. Ce tableau comporte des entiers de 1 à N, de tel sorte que une fois mélangé et lu il affiche une série de nombre de 1 à N dans le désordre, sans jamais ressortir deux fois le même nombre.

Deuxième défi : Rendre l'installation pilotable à distance
Contrainte chère à la scène l'installation doit être manipulable à distance par un opérateur situé en retrait de l'installation et à l'insu du public.

Pour répondre à cette contrainte nous avons utilisé une connection WiFi.
Afin d'être indépendant de l'environnement dans lequel est exposé l'installation nous avons fait le choix que l'installation emette son propre réseau, sur lequel nous avons utilisé la technique du "Portail Captif".
Le principe du portail captif est de restreindre l'accès à une unique page web en redirigeant l'ensemble des requetes vers cette page.
En l'occurence nous redirigeons l'ensemble des requètes vers la page permettant de piloter l'installation, ce qui permet à l'opérateur de facilement retrouver la page de configuration.
Cette technique est souvent utilisée pour les Wifi d'hotel ou d'hopitaux, ou toute première connection est renvoyée vers une page d'authentification avant de pouvoir naviguer sur l'internet.

Conception Artistique : MP0804h (Igor Deschamps)
Réalisation : Derrick Giscloux, Arthur Suzuki
04/10/2018

