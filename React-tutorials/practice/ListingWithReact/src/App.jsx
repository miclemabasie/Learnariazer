import { useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'
import PropertyList from './PropertyListing'

const App = () => {
  return (
    <div className="App">
      <h1>Hello world</h1>
      <PropertyList />
    </div>
  );
};

export default App
