file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

#include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty")

add_executable(${TArithmeticExpressiontest} ${srcs} ${hdrs}) #Создаем проект с именем из переменной ${stacktest}, в него добавляются файлы из переменных ${srcs} и ${hdrs}
target_link_libraries(${TArithmeticExpressiontest} ${TArithmeticExpressionlib} gtest) #Подключаем к проекту с именем ${stack} библиотеки с именами ${stacklib} и gtest
