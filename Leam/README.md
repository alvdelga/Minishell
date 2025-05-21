# Minishell

<p align="center">
  <img src="https://img.shields.io/badge/42-Project-blue.svg" />
  <img src="https://img.shields.io/badge/Status-In%20Progress-yellow" />
  <img src="https://img.shields.io/badge/Language-C-informational" />
  <img src="https://img.shields.io/badge/Start_Date-2025-04-02-lightgrey" />
</p>

## 🐚 Sobre el proyecto

**Minishell** es un proyecto de la escuela 42 que tiene como objetivo crear una shell mínima funcional, implementando algunas de las funcionalidades más esenciales de una terminal UNIX. Se centra principalmente en el manejo de procesos, señales, parsing de comandos y ejecución con redirecciones y pipes.

> El objetivo principal es aprender cómo funciona una shell desde dentro: creación de procesos, duplicación de fds, uso de `execve`, manejo de señales, estructuras de datos, parsing y más.

## 🚧 Estado actual

Estoy empezando este proyecto ahora mismo. El enfoque inicial será:

- [x] Leer el subject y entender los requisitos mínimos.
- [ ] Crear el esqueleto del parser.
- [ ] Preparar el entorno de ejecución de comandos simples.
- [ ] Implementar pipes y redirecciones.
- [ ] Añadir manejo de señales.
- [ ] Implementar comandos built-in (`cd`, `echo`, `export`, `unset`, etc).
- [ ] Manejar errores, memoria y código limpio.
- [ ] Bonus: expansión de variables y mejoras visuales.

## 🧠 Conceptos clave

- Forks & procesos hijos
- `execve`, `dup2`, `pipe`, `wait`, `signal`
- Parsing y estructuras de tokens
- Built-ins (implementados sin `execve`)
- Manejo del entorno (`envp`, `export`, etc)
- Heredocs y redirecciones (`>`, `<`, `>>`, `<<`)
- Señales (Ctrl+C, Ctrl+D)

## 📁 Estructura inicial (planeada)

```
minishell/
├── include/
│   └── minishell.h
├── src/
│   ├── main.c
│   ├── parser/
│   ├── executor/
│   ├── builtins/
│   └── utils/
├── libft/ (si se reutiliza)
├── Makefile
```

## 💡 Objetivo personal

Además de aprobar el proyecto, quiero entender cómo se construye una shell desde cero, escribir un código modular, limpio y mantenible, y mejorar mi manejo de procesos en C.

## 📚 Recursos útiles

- [TLPI - The Linux Programming Interface]
- [man pages de `fork`, `execve`, `dup2`, `pipe`, `signal`, `waitpid`]
- Proyecto Shell de Harvard CS50
- Repos de compañeros veteranos en 42

---

**Desarrollado por:** Álvaro Delgado Matud ([@alvdelga](https://github.com/alvdelga))  
**Escuela:** 42 Madrid  
