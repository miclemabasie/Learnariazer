function customerRnder(reactElement, container) {
    const domElement = document.createElement(reactElement.type)
    domElement.innerHTML = reactElement.children
    
}

const reactElement = {
  type: 'div',
  props: { id: 'app', href: 'https://reactjs.org', target: '_blank'},
  children: "click me for some more fun",
  somthing: [
    { type: 'h1', props: {}, children: ['Hello, Vite!'] },
    { type: 'img', props: { src: './react.svg' }, children: [] },]
}

const mainContainer = document.getElementById('root');
