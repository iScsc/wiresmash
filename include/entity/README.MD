## Constructeurs (Pole entity - Benoit - 05/01)
### Strategies
Pour la plupart des strategies le constructeur appelle simplement celui de la classe `Strategy`,
sauf pour `damageable` et `physical_entity` où il y a deux constructeurs :
- Un sans arguments qui initialise donc les paramètres avec des valeurs par defaut (genre vie, masse etc)
- Et donc un second ou on peut passer ces valeurs en arguments
### Character et Wall
Normalement les strategies sont créées par ces constructeurs, mais il y en a quand même un où on peut passer une liste de strategies.
Sinon il y a plusieurs constructeurs, toujours un sans arguments pour les valeurs par défaut, et pour `character` un où on peut choisir les paramètres.
### To Do
Traiter les hitbox dans le constructeur de `physical_entity`