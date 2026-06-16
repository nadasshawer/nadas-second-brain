## Containers

#### What Is a Container?

- A **container** is a way to package applications with all the necessary dependencies and configuration
- Portable artifact, easily shared and moved around
- Makes development and deployment more efficient
#### Where Do Containers Live?

**Containers live in:**
- A **container repository** → a special type of storage for containers
- Private repositories
- Public repository for Docker → *Docker Hub*
## Development & Deployment

#### How Containers Improved Development

**Before Containers:**
- Installation process different on each OS environment
- Many steps where something could go wrong

**With Containers:**
- No need to install any of the services directly on your OS because the container is its own isolated OS layer with a Linux based image
- So everything is packaged in **one isolated environment**
- Only one command to fetch the container and run it on any OS
#### How Containers Improved Deployment

**Before Containers:**
- Configuration of everything on the server is needed
- Dependency version conflicts
- Textual guide for the deployment process written by the development team for the production team can lead to misunderstandings

**With Containers:**
- Developers and operations work together to package the application in a container
- No environmental configuration needed on the server (except Docker runtime)
