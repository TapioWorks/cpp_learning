class Character:
    def __init__(self, name, health, attack_power, defense):
        self.name = name
        self.health = health
        self.attack_power = attack_power
        self.defense = defense
        self.heal_used = False

    def attack(self, other_character):
        damage = self.attack_power - other_character.defense

        if damage < 1:
            damage = 1

        other_character.health -= damage

        if other_character.health < 0:
            other_character.health = 0

        print(f"{self.name} attacks {other_character.name} for {damage} damage!")
        print(f"{other_character.name} has {other_character.health} HP remaining.\n")

    def heal(self, amount):
        if self.health == 100:
            print(f"{self.name} is already at full health!\n")
            return

        self.health = min(100, self.health + amount)
        self.heal_used = True

        print(f"{self.name} heals for {amount} HP!")
        print(f"{self.name} now has {self.health} HP.\n")

    def is_alive(self):
        return self.health > 0

    def show_stats(self):
        print(f"Character: {self.name}")
        print(f"Health: {self.health}")
        print(f"Attack: {self.attack_power}")
        print(f"Defense: {self.defense}")
        print("-" * 25)


class Battle:
    def __init__(self, character1, character2):
        self.character1 = character1
        self.character2 = character2

    def take_turn(self, attacker, defender):
        # Heal once if health gets low
        if attacker.health <= 30 and not attacker.heal_used:
            attacker.heal(20)
        else:
            attacker.attack(defender)

    def fight(self):
        print("===== BATTLE START =====\n")

        turn = 1

        while self.character1.is_alive() and self.character2.is_alive():
            print(f"--- Turn {turn} ---")

            self.take_turn(self.character1, self.character2)

            if not self.character2.is_alive():
                break

            self.take_turn(self.character2, self.character1)

            turn += 1

        print("===== BATTLE OVER =====\n")

        if self.character1.is_alive():
            print(f"The winner is {self.character1.name}!")
        else:
            print(f"The winner is {self.character2.name}!")

        print("\nFinal Stats:")
        self.character1.show_stats()
        self.character2.show_stats()


def main():
    hero = Character("Knight", 100, 18, 5)
    orc = Character("Orc", 100, 22, 2)

    battle = Battle(hero, orc)
    battle.fight()


if __name__ == "__main__":
    main()