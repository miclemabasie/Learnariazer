import { useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'

import Card  from "./components/Card"

function App() {

  return (
    <>
     <Card image="https://images.pexels.com/photos/27810045/pexels-photo-27810045.jpeg" username="Miclem" position="Lead Engineer"/>
     <Card image="https://images.pexels.com/photos/27601071/pexels-photo-27601071/free-photo-of-newlywed-couple-near-coeur-dalene-resort.jpeg?auto=compress&cs=tinysrgb&w=1260&h=750&dpr=1" username="Achiri" position="DevOps Engineer"/>
     <Card image="https://images.pexels.com/photos/27959484/pexels-photo-27959484/free-photo-of-a-pink-lotus-flower-with-a-yellow-center.jpeg?auto=compress&cs=tinysrgb&w=600&lazy=load" username="Brandy" position="Backend Engineer"/>
     <Card />
    </>
  )
}

export default App
