# Technical Test – Unreal Engine 5.7.4 Vehicle Movement

## Description

Ce projet Unreal Engine **5.7.4** présente un véhicule contrôlable par le joueur dans un environnement simple.

Le véhicule répond aux entrées clavier (**ZQSD**) ainsi qu'à la souris pour contrôler la caméra.

La logique de déplacement est entièrement développée en **C++** dans la classe `AVehiclePawn`, tandis que la rotation visuelle des roues est réalisée en **Blueprint** afin de séparer la logique de gameplay de la partie visuelle.

---

## Fonctionnalités

- Contrôle du véhicule avec **Enhanced Input**
- Vue troisième personne
- Accélération progressive
- Vitesse maximale configurable
- Direction progressive
- Rotation dépendante de la vitesse
- Marche avant et marche arrière
- Rotation visuelle des roues en Blueprint
- Paramètres de conduite modifiables directement depuis l'éditeur

---

## Choix techniques

| Élément | Choix |
|---------|--------|
| **Langage** | C++ pour la logique, Blueprint pour le visuel |
| **Input** | Enhanced Input (Input Mapping Context + Input Actions) |
| **Pawn** | `APawn` + `UFloatingPawnMovement` |
| **Caméra** | `USpringArmComponent` + `UCameraComponent` |
| **Déplacement** | Calcul manuel en C++ |

### Mouvement

Le véhicule utilise :

- une accélération progressive (`Acceleration`)
- une vitesse maximale (`MaxSpeed`)
- un frein moteur via `FInterpTo`
- une direction interpolée (`CurrentSteering`)
- une rotation dépendante de la vitesse
- une inversion de la direction lors de la marche arrière

---

# Paramètres du véhicule

Le comportement du véhicule est entièrement paramétrable depuis l'éditeur Unreal.

Toutes les variables importantes sont exposées dans la catégorie **Vehicle**, permettant de modifier rapidement les sensations de conduite sans recompiler le projet.

| Variable | Description |
|----------|-------------|
| **Acceleration** | Force appliquée chaque Tick pour accélérer |
| **Max Speed** | Vitesse maximale avant/arrière |
| **Steering Angle** | Angle maximal de braquage |
| **Steering Speed** | Vitesse d'interpolation du volant |

Ces paramètres permettent par exemple de créer facilement :

- une conduite arcade
- une conduite plus réaliste
- un véhicule léger
- un véhicule lourd
- différents prototypes de gameplay

---

# Blueprint

Le Blueprint gère uniquement la partie visuelle.

À chaque Tick :

- rotation des roues selon la vitesse du véhicule
- orientation des roues avant selon l'angle de direction

Toute la logique de déplacement reste en C++.

---

# Architecture du projet

```text
TechnicalTest/
│
├── Source/
│   └── TechnicalTest/
│       ├── VehiclePawn.h
│       └── VehiclePawn.cpp
│
├── Content/
│   ├── Blueprints/
│   │   ├── BP_GameMode
│   │   ├── BP_VehicleController
│   │   └── BP_VehiclePawn
│   │
│   ├── Inputs/
│   │   ├── IMC_Vehicle
│   │   └── Actions/
│   │       ├── IA_Look
│   │       ├── IA_MoveForward
│   │       └── IA_MoveRight
│   │
│   ├── Levels/
│   │   ├── LevelTest
│   │   └── LevelTest_HLOD_Instancing
│
├── Config/
├── Docs/
└── README.md
```

---

# Installation

## 1. Cloner le dépôt

```bash
git clone https://github.com/Maxiltron/UE5-VehicleMovement-TechnicalTest.git
```

## 2. Ouvrir le projet

Ouvrir le fichier `.uproject` avec **Unreal Engine 5.7.4**.

Si nécessaire, laisser Unreal générer les fichiers Visual Studio.

## 3. Compiler

Compiler le projet depuis :

- Unreal Engine
- ou Visual Studio

## 4. Lancer le jeu

Ouvrir la map **LevelTest** puis cliquer sur **Play**.

---

# Contrôles

| Touche | Action |
|---------|--------|
| **Z** | Avancer |
| **S** | Reculer |
| **Q** | Tourner à gauche |
| **D** | Tourner à droite |
| **Souris** | Rotation de la caméra |
| **Échap** | Quitter le jeu |

---

# Outils utilisés

- Unreal Engine 5.7.4
- C++
- Blueprint
- Enhanced Input
- Visual Studio

---

# Utilisation de l'IA

L'IA a été utilisée comme assistance au développement pour :

- proposer une structure de code C++
- suggérer des bonnes pratiques Unreal Engine
- améliorer l'organisation du projet
- assister la rédaction du README

L'ensemble des choix techniques, du code et de l'architecture ont été relus, adaptés et validés manuellement.

---

# Dépôt GitHub

**Repository :**

https://github.com/Maxiltron/UE5-VehicleMovement-TechnicalTest