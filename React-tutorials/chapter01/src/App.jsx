import React from 'react'
import Youtube from './Youtube.jsx'
import { useState } from 'react';

function App() {

  const [counter, setCounter] = useState(0)
  
  const addOne = () => {
    setCounter((value) => value + 1);
  }

  const removeOne = () => {
    if(counter>0){
      setCounter(counter-1)
    }else{

      alert("Can not go below 0")
    }
  };
  
  return (
    <>
      <h1>React Course with Miclem {counter}</h1>
      <h2>Counter Value: {counter}</h2>
      <button onClick={addOne}>Add Value</button>{" "}
      <button onClick={removeOne}>Remove Value</button>
      <Youtube />
    </>
  )
}

export default App