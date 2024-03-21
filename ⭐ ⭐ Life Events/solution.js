// O(n), where n is the number of life events
// If unsorted, iterate over the life events array.
// If you see a birth year value less than or equal to the target year, increment a counter of people alive up until that year.
// If you see a death year value less than or equal to the target year, decrement the counter of people alive up until that year.
// If sorted, you can do an early stop once the birth year value exceeds the target year.
function findPopulationSize(lifeEvents, year) {
    const populationSize = 0;
    for (let lifeEvent in lifeEvents) {
        const { birthYear, deathYear } = lifeEvent;
        if (birthYear <= year) {
            populationSize++;
        }
        if (deathYear <= year) {
            populationSize--;
        }
    }
    return populationSize;
}

// Modification 1
// O(n * k) time, O(k) space, where k is the full possible range of years
function findMaxPopulationSize(lifeEvents) {
    const populationPerYear = {};
    for (let lifeEvent in lifeEvents) {
        const { birthYear, deathYear } = lifeEvent;
        for (const year = birthYear; year <= deathYear; year++) {
            if (!populationPerYear[birthYear]) {
                populationPerYear[birthYear] = 1;
            } else {
                populationPerYear[birthYear]++;
            }
        }
    }
    
    const maxPopulation = { size: 0, year: 0 };
    for (let year of populationPerYear) {
        const currentPopulationSize = populationPerYear[year];
        if (maxPopulation.size < currentPopulationSize) {
            maxPopulation.size = currentPopulationSize;
            maxPopulation.year = year;
        }
    }

    return maxPopulation;
}

0, 10
0, 12
0, 15