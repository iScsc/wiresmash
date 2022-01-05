#PHX README
##PHX/PFD

- Use unsigned int from 0 to MAX_INT to calculate the physics
- Positions are unsigned int pairs, Vectors are signed int pairs. These types are declared in lib.
- updateCinematics act like the pfd. Do not take into account collisions.
  Param: PhysicalEntity
  Output: correction velocity to apply

##PHX/HITBOX

/--------------------voici les fonctions pour créer une hitbox : 

dans cette partie, les coordonnées sont données suivant la conventions de la partie ETT, les fonctions convertissent directement dans les conventions de la partie phx
rappel conventions : 
ETT --> sens trigo, (0, 0) en haut à gauche avec pour un point (x, y) x positif vers la droite et y positif vers le bas de l'écran
phx --> sens trigo, (0, 0) en bas à gauche avec pour un point (x, y) x positif vers la droite et y positif vers le haut de l'écran


1) Hitbox(unsigned int size = 2)
déclarez :
Hitbox H;
Hitbox H(size);

elle créer une hitbox remplie de (0, 0)

la valeur par défaut de la taille de la hitbox (nombre de points la composant) est de 2 (mettre autre chose ne change rien, c'est simplement au cas où il y aurait besoin de hitbox plus complèxes)
J'ai choisi la valeur de 2 car la plupart de nos hitbox seront des rectangles, il suffit donc uniquement de préciser 2 angles opposés (pour la création ces angles sont l'angle en haut à gauche et celui en bas à droite, ça me paraissait plus proche de la convention de la partie ETT)


2) Hitbox(unsigned int H[][2], unsigned int size = 2)
déclarez :
Hitbox H(A);
Hitbox H(A, size);

avec : unsigned int A[][2] = {{x1, y1}, {x2, y2}}    (on peut mettre plus de points mais seuls les 2 premiers seront conservés, en prévisions de hitbox plus complèxes)
(n'hésitez pas à me dire si vous préféreriez un autre type que 'array' en entrée)


3) void setPoint(unsigned int i, unsigned int x, unsigned int y);
déclarez :
setPoint(i, x, y);
i == 0 --> angle en haut à gauche
i != 0 --> angle en bas à droite (encore une fois on peut rentrer autre chose que 0 ou 1 en prévision de hitbox plus complèxes)

x et y sont à rentrer en convention ETT



/--------------------voici les fonctions pour connaître une hitbox : 

tout est renvoyer en conventions phx, j'ai choisi de faire ainsi car à priori la partie ETT ne fait que créer des hitbox et la partie phx ne fait que demander à les connaître (si vous penser que vous avez besoin d'une fonction qui n'est pas dans votre convention n'hésitez pas à me le dire, je changerais ça)

1) unsigned int size()
déclarez :
unsigned int s = H.size();

ça renvoie évidemment la variable size associée à la hitbox (si une valeur autre que 2 a été rentrée, elle sera renvoyée bien qu'en vrai la hitbox sera de taille 2 tant qu'il n'y a pas de hitbox plus complète)


2) std::vector<std::pair<unsigned int, unsigned int>> getHitbox()
déclarez :
std::vector<std::pair<unsigned int, unsigned int>> V = H.getHitbox();

renvoie un vecteur de couple, pour l'instant c'est un vecteur de 2 couples : le point en BAS à GAUCHE et celui en HAUT à DROITE car je trouvais que cela collait plus aux conventions phx (évidemment les coordonnées sont en conventions phx)



(comme je débute en C++, peut être que j'ignore d'autre façon de déclarer mes fonctions mais en tout cas les déclarations proposées sont normalement fonctionnelles et testées)
comme c'est souvent marqué, j'ai codé au cas où on déciderait de faire des hitbox différentes donc si jamais cela devait arriver, tout le code se servant des hitbox rectangulaires ne serait PAS à changer, les mêmes déclarations, les mêmes renvois de fonctions,...
un cas que je n'ai pas vraiment pris en compte c'est le cas de hitbox en ellipse, mais à ce moment je pense que seul la partie phx devrait rajouter du code pour savoir si la hitbox est polygonale ou en ellipse en appelant une fonction H.isPoly() ou quelque chose du genre (j'imagien que si ça devait arriver, je ferais une hitbox avec comme variable : le centre et les 2 demi-rayons)
