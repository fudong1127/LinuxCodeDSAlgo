#####################################################################
# Trie datastructure implementation
# Author:Arup Upadhayay
# Date:21st Sept 2013
######################################################################

#variable defination
CC = g++
CFLAGS = -Wall -g -O2
OBJ_DIR=obj_dir
include make_SRC

TARGET:$(TARGET_OBJ)
	$(CC) $(CFLAGS) -o TARGET $(TARGET_OBJ)
	
$(OBJ_DIR)/%.o:%.cpp
	$(CC) $(CFLAGS) -o $@ -c $<
	 	 
README:
	@echo $(TARGET_OBJ)

#Cleans all the *.exe files
clean:
	rm -f ./TARGET ./obj_dir/*.o
