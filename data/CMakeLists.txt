install(FILES kamerka.desktop DESTINATION ${XDG_APPS_INSTALL_DIR})
install(FILES camera_click.ogg timer.ogg DESTINATION "${DATA_INSTALL_DIR}/kamerka")
install(FILES kamerka.notifyrc DESTINATION ${KNOTIFYRC_INSTALL_DIR})
install(FILES kamerka.png DESTINATION "share/pixmaps")
install(FILES kamerka.1 DESTINATION "${MAN_INSTALL_DIR}/man1")
