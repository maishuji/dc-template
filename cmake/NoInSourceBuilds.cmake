if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
    message(FATAL_ERROR
        "\n"
        "In-source builds are not allowed.\n"
        "Instead, provide a path to build tree with -B flag\n"
        "Usage: cmake -B <destination> \n"    
    )
endif()