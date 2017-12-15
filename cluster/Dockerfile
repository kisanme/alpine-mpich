FROM nlknguyen/alpine-mpich:onbuild

# # ------------------------------------------------------------
# # Build MPI project
# # ------------------------------------------------------------

# Put all build steps and additional package installation here
USER root
RUN apk update
RUN apk add vim

RUN echo "alias ll='ls -alh'" >> /home/${USER}/.profile
RUN chown root:${USER} /home/${USER}/.profile
USER ${USER}
RUN source ~/.profile

# Note: the current directory is ${WORKDIR:=/project}, which is
# also the default directory where ${USER:=mpi} will SSH login to

# Copy the content of `project` directory in the host machine to 
# the current working directory in this Docker image
COPY project/ .

# Normal build command
RUN mpicc -o mpi_hello_world mpi_hello_world.c
RUN mpicc -o add_set_of_numbers add_set_of_numbers.c
RUN mpicc -o mpi_first mpi_first.c
RUN mpicc -o p2p_message_passing p2p_message_passing.c
RUN mpicc -o send_recieve send_recieve.c

# ####################
# For Docker beginner:

# After Docker syntax `RUN`, you can execute any command available in 
# the current shell of the image.

# To switch to root:    USER root
# To switch back to default user: USER ${USER}
