# Zombie Land

## Dependencies
On Arch just do this:
``` 
sudo pacman -S ninja cmake
```

## Building
run this command while in the project directory to build and run the project
``` 
./brun_linux.sh
```

# TODO

1.  [ V ] Camera movement 
2.  [ V ] World
3.  [ X ] Player interaction with enemies, visible player and enemy stats
4.  [ X ] Level up mechanic
5.  [ X ] Enemy wave system
6.  [ X ] Inventory, Weapons and Armor
7.  [ X ] Sounds

Klasy:

- Game (Klasa przechowująca cały program, łączy wszystkie inne klasy)

- Axis( Przechowuje pozycję obiektów jako x i y )

- Character dziedziczy Axis(
Klasa bazowa wszystkich postaci zawieraja podstawowe funkcje takie jak getPosition, set position oraz zmiennej jak zdrowie)

- Enemy dziedziczy Character( Przechowuje dane o przeciwniku)

- Player dziedziczy Character( Podstawowa klasa Postaci gracza zawiera między innymi zmienną z punktami doświadczenia oraz funkcje która sprawia że postać zmienia rotację na bazie myszki)

- Window_Resolution( Przechowuje i aktualizuję rozdzielczość okna)

- Camera ( podąża za postacią upewniając się że cel jest zawsze na środku)

- TerrainGenerator( Generuję texture odrobinę większą niż postac i zależnie od kierunku w jakim się rusza gracz przemieszcza texture terenu co daje iluzje nieskończonego świata )