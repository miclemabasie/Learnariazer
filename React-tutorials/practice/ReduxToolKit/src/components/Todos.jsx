import React from 'react'
import { useSelector } from 'react-redux'
import { useDispatch } from 'react-redux'
import { removeTodo } from '../features/todo/todoSlice'

function Todos() {

   const todos = useSelector(state => state.todos)
   const dispatch = useDispatch()

  return (
    <>
    <div>Todos</div>
    {todos.map((todo) => (
        <div 
        className='flex flex-row border p-2 text-white bg-slate-900 rounded-md justify-between' 
        key={todo.id}>{todo.text}
        <button 
        onClick={() => dispatch(removeTodo(todo.id))}
        >🗑️</button>
        </div>
    ))}
    </>
  )
}

export default Todos