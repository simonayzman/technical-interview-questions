class InstaRandom {
    constructor() {
        this.map = {};
        this.indexMap = {};
        this.array = [];
    }

    insert(key, value) {
        this.map[key] = value;
        this.array.push(key);
        this.indexMap[key] = this.array.size() - 1;
    }

    remove(key) {
        this.map[key] = undefined;
        for (let i = 0; i < this.array.size(); i++) {
            if (this.array[i] === key) {
                this.array[i] = this.array[this.array.size() - 1];
                this.array.popBack();
            }
        }
    }

    contains(key) {
        return this.map[key] != null;
    }

    getRandom() {
        let result = { key: null, value: null };
        const randomIndex = getRandomInt(0, this.array.size() - 1);
        result.key = this.array[randomIndex];
        result.value = this.map[result.key];
        return result;
    }
}