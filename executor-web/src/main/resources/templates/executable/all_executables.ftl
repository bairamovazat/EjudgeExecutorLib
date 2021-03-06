<#ftl encoding='UTF-8'>
<!DOCTYPE html>
<html>
<#include "../head.ftl">
<body>
<#include "../header.ftl">
<div class="container-fluid">
    <div class="row">
        <div class="col-md-1 col-lg-2 col-xs-3">

        </div>
        <div class="col-12 col-sm-12 col-md-10 col-lg-8 col-xs-6">
            <div style="text-align: center">
                <h3>
                    Список выполняемых файлов <a href="create"><button class="btn btn-primary">Добавить</button></a>
                </h3>
            </div>
            <div class="table-responsive">
                <table class="table table-striped">
                    <thead>
                    <tr>
                        <th scope="col">#</th>
                        <th scope="col">Название</th>
                        <th scope="col">Тип</th>
                        <th scope="col">Хеш</th>
                        <th scope="col">Описание</th>
                        <th scope="col">Название файла</th>
                        <th scope="col">Тип файла</th>

                    </tr>
                    </thead>
                    <tbody>
                    <#list model.executables as executable>
                        <tr>
                            <td><a href="create?executableId=${executable.id}">${executable.id!}</a></td>
                            <td>${executable.name!}</td>
                            <td>${executable.type!}</td>
                            <td>${executable.md5sum!}</td>
                            <td>${executable.description!}</td>
                            <td>${executable.fileName!}</td>
                            <td>${executable.fileType!}</td>
                        </tr>
                    </#list>
                    </tbody>
                </table>
            </div>
            <nav aria-label="navigation">
                <ul class="pagination justify-content-center">
                    <li class="page-item ${((model.currentPage == 0)?string("disabled",""))}">
                        <a class="page-link" href="?page=${model.currentPage - 1}" tabindex="-1">Previous</a>
                    </li>

                    <#list model.pageList as page>
                        <li class="page-item ${((page == model.currentPage)?string("active",""))}">
                            <a class="page-link" href="?page=${page}">
                                ${page}
                            </a>
                        </li>
                    </#list>

                    <li class="page-item
                        ${((model.pageList?size <= 0 || model.currentPage == model.pageList[model.pageList?size - 1])?string("disabled",""))}
                        ">
                        <a class="page-link" href="?page=${model.currentPage + 1}">Next</a>
                    </li>
                </ul>
            </nav>
        </div>
        <div class="col-md-1 col-lg-2 col-xs-3">

        </div>
    </div>
</div>

<#include "../footer.ftl">
</body>
</html>
