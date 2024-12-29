
import React from 'react'
import {Logo, LogoutBtn, Container} from "../"
import { Link } from 'react-router-dom'
import { useNavigate } from 'react-router-dom'
import { useSelector } from 'react-redux'


function Header() {
    const authStatus = useSelector((state) => state.auth.status)

    const navigate = useNavigate()

    const navItems = [
        {
            name: "Home",
            slug: "/",
            active: true
        },
        {
            name: "Login",
            slug: "/login",
            active: !authStatus
        },
        {
            name: "Signup",
            slug: "/signup",
            active: !authStatus
        },
        {
            name: "All Posts",
            slug: "/all-osts",
            active: authStatus
        },
        {
            name: "Add Post",
            slug: "/add-post",
            active: authStatus
        },
        
    ]
  return (
    <header
    className='py-3 shadow bg-gray-500'
    >
        <Container>
            <nav className='flex justify-between'>
                <div className="mr-4">
                    <Link>
                        <Logo />
                    </Link>
                </div>
                <ul className='flex gap-2'>
                    {navItems.map((item) => item.active ? (
                        <li className='gap-3' key={item.name}>
                            <Link 
                            className='inline-block px-6 py-2 duration-200 hover:bg-blue-100 rounded-full'
                            to={item.slug}>{item.name}</Link>
                        </li>
                    ) : null)}

                    {
                        authStatus && ( 
                            <li>
                                <LogoutBtn /> 
                            </li>
                        )
                    }
                </ul>
            </nav>
        </Container>
    </header>
  )
}
// {navItems.map((item) => {
    // <li className='text-red-500'>{item.name}</li>
// })}

export default Header