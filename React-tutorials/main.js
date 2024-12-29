const person = {
    name: 'John Doe',
    age: 30,
    greet() {
        console.log(`Hello, my name is ${this.name}!`);
    }
}

const {name, age} = person;

// spread operator

const first = [1,2 ,3, 4]
const second = [5, 6, 7]

const combined = [...first, ...second]