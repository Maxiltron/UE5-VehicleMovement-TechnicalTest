# \# Technical Test – Unreal Engine 5.7.4 Vehicle Movement

# 

# \## Description

# 

# Ce projet Unreal Engine 5.7.4 présente un véhicule contrôlable par le joueur dans un environnement simple.

# Le véhicule répond aux entrées clavier (ZQSD) et à la souris pour la caméra.  

# Le déplacement est géré en C++ (classe `AVehiclePawn`) et la rotation visuelle des roues est gérée en Blueprint.

# 

# \## Choix techniques

# 

# \- \*\*Langage :\*\* C++ pour la logique de mouvement, Blueprint pour la partie visuelle (roues).

# \- \*\*Système d’input :\*\* Enhanced Input (Input Mapping Context + Input Actions).

# \- \*\*Type de Pawn :\*\* `APawn` avec `UFloatingPawnMovement` pour un contrôle simple et lisible.

# \- \*\*Caméra :\*\* `USpringArmComponent` + `UCameraComponent` pour une vue troisième personne.

# \- \*\*Mouvement :\*\*

# &#x20; - Accélération progressive (`Acceleration`, `MaxSpeed`).

# &#x20; - Friction et frein moteur (`FInterpTo` vers 0).

# &#x20; - Direction progressive (`CurrentSteering` interpolé).

# &#x20; - Rotation dépendante de la vitesse (plus la voiture va vite, plus elle tourne).

# \- \*\*Blueprint :\*\*

# &#x20; - Tick Blueprint pour la rotation des roues (roulement + direction des roues avant).

# 

# \## Lancer le projet

# 

# 1\. Cloner le dépôt :

# &#x20;  ```bash

# &#x20;  git clone <URL\_DU\_REPO>



