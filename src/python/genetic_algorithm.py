"""
Genetic algorithm example
In this example we will create a generic genetic algorithm
that can be applied to solve many problems.
"""

from abc import ABC, abstractmethod
from copy import deepcopy
from enum import Enum
from heapq import nlargest
from random import choices, random, randrange
from statistics import mean


class Chromosome(ABC):
    @abstractmethod
    def fitness(self):
        pass

    @classmethod
    @abstractmethod
    def random_instance(cls):
        pass

    @abstractmethod
    def crossover(self, other):
        pass

    @abstractmethod
    def mutate(self):
        pass


SelectionType = Enum('SelectionType', 'ROULETTE TOURNAMENT')


class GeneticAlgorithm:
    def __init__(
        self,
        initial_population,
        threshold,
        max_generations=100,
        mutation_chance=0.01,
        crossover_chance=0.7,
        selection_type=SelectionType.TOURNAMENT,
    ):
        self._population = initial_population
        self._threshold = threshold
        self._max_generations = max_generations
        self._mutation_chance = mutation_chance
        self._crossover_chance = crossover_chance
        self._selection_type = selection_type
        self._fitness_key = type(self._population[0]).fitness

    def _pick_roulette(self, wheel):
        """Choose 2 random participants based on probability (fitness)."""
        return tuple(choices(self._population, weights=wheel, k=2))

    def _pick_tournament(self, num_participants):
        """Choose the 2 best participants from a random list."""
        participants = choices(self._population, k=num_participants)
        return tuple(nlargest(2, participants, key=self._fitness_key))

    def _reproduce_and_replace(self):
        """Create a new generation of population."""
        new_population = list()
        while len(new_population) < len(self._population):
            if self._selection_type == SelectionType.ROULETTE:
                parents = self._pick_roulette(
                    [p.fitness() for p in self._population]
                )
            else:
                parents = self._pick_tournament(len(self._population) // 2)
            # Try to perform a crossover with parents
            if random() < self._crossover_chance:
                new_population.extend(parents[0].crossover(parents[1]))
            else:
                new_population.extend(parents)
        if len(new_population) > len(self._population):
            new_population.pop()
        self._population = new_population

    def _mutate(self):
        """Try to perform a mutation for each individual."""
        for individual in self._population:
            if random() < self._mutation_chance:
                individual.mutate()

    def run(self):
        """Main function responsible for running the algorithm."""
        best = max(self._population, key=self._fitness_key)
        for generation in range(self._max_generations):
            if best.fitness() >= self._threshold:
                return best
            print(
                f'Generation {generation} Best {best.fitness()} '
                f'Avg {mean(map(self._fitness_key, self._population))}'
            )
            self._reproduce_and_replace()
            self._mutate()
            highest = max(self._population, key=self._fitness_key)
            if highest.fitness() > best.fitness():
                best = highest
        return best


# Now, let's use the generic algorithm to solve a simple equation.
# In this example we want to maximize the following equation:
# 6x - x^2 + 4y - y^2
# Tip: the answer should be: x = 3 and y = 2


class SimpleEquation(Chromosome):
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def fitness(self):
        """Calculate the equation."""
        return 6 * self.x - self.x * self.x + 4 * self.y - self.y * self.y

    @classmethod
    def random_instance(cls):
        """Create a new random object of SimpleEquation."""
        return SimpleEquation(randrange(100), randrange(100))

    def crossover(self, other):
        """Combine two SimpleEquation parents."""
        child1 = deepcopy(self)
        child2 = deepcopy(other)
        child1.y = other.y
        child2.y = self.y
        return child1, child2

    def mutate(self):
        """Mutate the current SimpleEquation object."""
        # Try to mutate X
        if random() < 0.5:
            if random() < 0.5:
                self.x += 1
            else:
                self.y -= 1
        else:
            if random() < 0.5:
                self.y += 1
            else:
                self.y -= 1

    def __str__(self):
        return f'X: {self.x} Y: {self.y} Fitness: {self.fitness()}'


if __name__ == '__main__':
    initial_population = [SimpleEquation.random_instance() for _ in range(20)]
    ga = GeneticAlgorithm(
        initial_population=initial_population,
        threshold=13.0,
        max_generations=100,
        mutation_chance=0.1,
        crossover_chance=0.7,
    )
    result = ga.run()
    print(result)
