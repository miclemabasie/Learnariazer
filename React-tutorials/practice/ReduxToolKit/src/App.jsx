import { useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'
import AddTodo from './components/AddTodo'
import Todos from './components/Todos'

const App = () => {
  return (
    <h1 className="text-3xl font-bold">
      <AddTodo />
      <Todos />
    </h1>
  )
}

export default App
