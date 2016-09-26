project(BrunelTests)

set(HEADER_FILES
        PatBBDTSeedClassifier.h
    )

set(SOURCE_FILES
        PatBBDTSeedClassifier.cpp
    )

add_library(BrunelTests STATIC ${SOURCE_FILES} ${HEADER_FILES})
